#include "global.h"
#include "day_night.h"
#include "decompress.h"
#include "event_data.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "overworld.h"
#include "palette.h"
#include "rtc.h"
#include "constants/day_night.h"
#include "constants/rgb.h"
#include "strings.h"
#include "string_util.h"
#include "fieldmap.h"

#define TINT_MORNING Q_8_8(0.7), Q_8_8(0.7), Q_8_8(0.9)
#define TINT_DAY Q_8_8(1.0), Q_8_8(1.0), Q_8_8(1.0)
#define TINT_NIGHT Q_8_8(0.4), Q_8_8(0.4), Q_8_8(0.92)
#define TINT_LATE_NIGHT Q_8_8(0.3), Q_8_8(0.3), Q_8_8(0.8)

ALIGNED(4) EWRAM_DATA u16 gPlttBufferPreDN[PLTT_BUFFER_SIZE] = {0};
EWRAM_DATA const struct PaletteOverride *gPaletteOverrides[4] = {NULL};

static EWRAM_DATA struct {
    bool8 initialized:1;
    bool8 retintPhase:1;
    u8 timeOfDay;
    u16 prevTintPeriod; // tint period associated with currently drawn palettes
    u16 currTintPeriod; // tint period associated with currRGBTint
    u16 currRGBTint[3];
} sDNSystemControl = {0};

static const u16 sTimeOfDayTints[][3] = {
    [0] =   {TINT_LATE_NIGHT},
    [1] =   {TINT_LATE_NIGHT},
    [2] =   {TINT_NIGHT},
    [3] =   {TINT_NIGHT},
    [4] =   {Q_8_8(0.6), Q_8_8(0.65), Q_8_8(1.0)},
    [5] =   {TINT_MORNING},
    [6] =   {TINT_MORNING},
    [7] =   {TINT_MORNING},
    [8] =   {Q_8_8(0.9), Q_8_8(0.85), Q_8_8(1.0)},
    [9] =   {Q_8_8(1.0), Q_8_8(0.9), Q_8_8(1.0)},
    [10] =  {TINT_DAY},
    [11] =  {TINT_DAY},
    [12] =  {TINT_DAY},
    [13] =  {TINT_DAY},
    [14] =  {TINT_DAY},
    [15] =  {Q_8_8(1.0), Q_8_8(1.0), Q_8_8(0.91)},
    [16] =  {Q_8_8(0.92), Q_8_8(0.85), Q_8_8(0.81)},
    [17] =  {Q_8_8(0.78), Q_8_8(0.73), Q_8_8(0.53)},
    [18] =  {Q_8_8(0.74), Q_8_8(0.52), Q_8_8(0.49)},
    [19] =  {Q_8_8(0.56), Q_8_8(0.56), Q_8_8(0.68)},
    [20] =  {TINT_NIGHT},
    [21] =  {TINT_NIGHT},
    [22] =  {TINT_LATE_NIGHT},
    [23] =  {TINT_LATE_NIGHT},
};

static bool32 IsBetweenHours2(s32 hour, s32 begin, s32 end)
{
    if (end < begin)
    {
        if (hour >= begin)
            return TRUE;

        if (hour < end)
            return TRUE;
    }
    else
    {
        if (hour >= begin)
        {
            if (hour < end)
                return TRUE;
        }
    }
    return FALSE;
}


u8 GetCurrentTimeOfDay(void)
{
    if (gLocalTime.hours < HOUR_MORNING)
        return TIME_NIGHT;
    else if (gLocalTime.hours < HOUR_DAY)
        return TIME_MORNING;
    else if (gLocalTime.hours < HOUR_NIGHT)
        return TIME_DAY;

    return TIME_NIGHT;
}

static void LoadPaletteOverrides(void)
{
    u32 i, j;

    for (i = 0; i < ARRAY_COUNT(gPaletteOverrides); i++)
    {
        const struct PaletteOverride *curr = gPaletteOverrides[i];
        if (curr != NULL)
        {
            while (curr->slot != PALOVER_LIST_TERM && curr->palette != NULL)
            {
                s8 hour = gLocalTime.hours;
                if (IsBetweenHours2(hour, curr->startHour, curr->endHour))
                {
                    const u16 *src = curr->palette;
                    u16 *dest = &gPlttBufferUnfaded[PLTT_ID(curr->slot)];
                    for (j = 0; j < 16; j++)
                    {
                        if (*src != RGB_BLACK)
                            *dest = *src;
                        src++;
                        dest++;
                    }
                }
                curr++;
            }
        }
    }
}

static u32 LerpColor(u16 color1, u16 color2, u8 coeff)
{
    return (((color2 - color1) * coeff) / TINT_PERIODS_PER_HOUR) + color1;
}

static void LerpColors(s32 hour, u8 coeff)
{
    const u16 *rgb1, *rgb2;
    u16 rgbTemp[3];

    rgb1 = sTimeOfDayTints[hour];
    memcpy(rgbTemp, rgb1, sizeof(rgbTemp));

    rgb2 = sTimeOfDayTints[(hour + 1) % HOURS_PER_DAY];
    if (rgb1 != rgb2)
    {
        rgbTemp[0] = LerpColor(rgb1[0], rgb2[0], coeff);
        rgbTemp[1] = LerpColor(rgb1[1], rgb2[1], coeff);
        rgbTemp[2] = LerpColor(rgb1[2], rgb2[2], coeff);
    }

    if (rgbTemp != sDNSystemControl.currRGBTint)
        memcpy(sDNSystemControl.currRGBTint, rgbTemp, sizeof(rgbTemp));
}


static void TintPalette_CustomToneWithCopy(u16 offset, u16 count, bool32 excludeZeroes)
{
    s32 r, g, b, i;
    const u16 *src = &gPlttBufferPreDN[offset];
    u16 *dest = &gPlttBufferUnfaded[offset];

    for (i = 0; i < count; i++, src++, dest++)
    {
        if (excludeZeroes && *src == RGB_BLACK)
            continue;

        r = GET_R(*src);
        g = GET_G(*src);
        b = GET_B(*src);

        r = (u16)((sDNSystemControl.currRGBTint[0] * r)) >> 8;
        g = (u16)((sDNSystemControl.currRGBTint[1] * g)) >> 8;
        b = (u16)((sDNSystemControl.currRGBTint[2] * b)) >> 8;

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = RGB2(r, g, b);
    }
}

static void TintPaletteForDayNight(u16 offset, u16 size)
{
    if (IsMapTypeOutdoors(gMapHeader.mapType))
    {
        s32 hour;
        u8 hourPhase;
        u32 period;

        RtcCalcLocalTimeFast();

        hour = gLocalTime.hours;
        hourPhase = gLocalTime.minutes / MINUTES_PER_TINT_PERIOD;

        period = (hour * TINT_PERIODS_PER_HOUR) + hourPhase;

        if (!sDNSystemControl.initialized || sDNSystemControl.currTintPeriod != period)
        {
            sDNSystemControl.initialized = TRUE;
            sDNSystemControl.currTintPeriod = period;
            LerpColors(hour, hourPhase);
        }

        TintPalette_CustomToneWithCopy(offset, size / 2, FALSE);
        LoadPaletteOverrides();
    }
    else
    {
        CpuCopy16(&gPlttBufferPreDN[offset], &gPlttBufferUnfaded[offset], size);
    }
}

void LoadCompressedPaletteDayNight(const u32 *src, u16 offset, u16 size)
{
    LoadCompressedPalette_HandleDayNight(src, offset, size, TRUE);
}

void LoadPaletteDayNight(const void *src, u16 offset, u16 size)
{
    LoadPalette_HandleDayNight(src, offset, size, TRUE);
}

void CheckClockForImmediateTimeEvents(void)
{
    if (!sDNSystemControl.retintPhase && IsMapTypeOutdoors(gMapHeader.mapType))
        RtcCalcLocalTimeFast();
}

void FillDNPlttBufferWithBlack(u32 offset, u16 size)
{
    CpuFill16(RGB_BLACK, &gPlttBufferPreDN[offset], size);
}

void ProcessImmediateTimeEvents(void)
{
    u32 timeOfDay;

    if (IsMapTypeOutdoors(gMapHeader.mapType))
    {
        if (sDNSystemControl.retintPhase)
        {
            sDNSystemControl.retintPhase = FALSE;
            TintPalette_CustomToneWithCopy(BG_PLTT_SIZE / 2, OBJ_PLTT_SIZE / 2, TRUE);
            LoadPaletteOverrides();

            if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_IN
             && gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
            {
                u32 paletteIndex;

                CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
                for (paletteIndex = 0; paletteIndex < NUM_PALS_TOTAL; paletteIndex++)
                {
                    ApplyWeatherColorMapToPal(paletteIndex);
                    UpdateSpritePaletteWithWeather(paletteIndex);
                }
            }
        }
        else
        {
            s32 hour;
            u8 hourPhase;
            u32 period;

            hour = gLocalTime.hours;
            hourPhase = gLocalTime.minutes / MINUTES_PER_TINT_PERIOD;

            period = (hour * TINT_PERIODS_PER_HOUR) + hourPhase;

            if (!sDNSystemControl.initialized || sDNSystemControl.prevTintPeriod != period)
            {
                sDNSystemControl.initialized = TRUE;
                sDNSystemControl.prevTintPeriod = sDNSystemControl.currTintPeriod = period;
                LerpColors(hour, hourPhase);
                TintPalette_CustomToneWithCopy(0, BG_PLTT_SIZE / 2, TRUE);
                sDNSystemControl.retintPhase = TRUE;
            }
        }
    }

    timeOfDay = GetTimeOfDay();
    if (sDNSystemControl.timeOfDay != timeOfDay)
    {
        sDNSystemControl.timeOfDay = timeOfDay;
        ChooseAmbientCrySpecies(); // so a time-of-day appropriate Pokémon is chosen
        ForceTimeBasedEvents();    // for misc events that should run on time of day boundaries
    }
}

void LoadCompressedPalette_HandleDayNight(const u32 *src, u16 offset, u16 size, bool32 isDayNight)
{
    LZ77UnCompWram(src, gPaletteDecompressionBuffer);
    LoadPalette_HandleDayNight(gPaletteDecompressionBuffer, offset, size, isDayNight);
}

void LoadPalette_HandleDayNight(const void *src, u16 offset, u16 size, bool32 isDayNight)
{
    if (isDayNight)
    {
        CpuCopy16(src, &gPlttBufferPreDN[offset], size);
        TintPaletteForDayNight(offset, size);
    }
    else
    {
        CpuFill16(RGB_BLACK, &gPlttBufferPreDN[offset], size);
        CpuCopy16(src, &gPlttBufferUnfaded[offset], size);
    }
    CpuCopy16(&gPlttBufferUnfaded[offset], &gPlttBufferFaded[offset], size);
}