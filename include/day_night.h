#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

#include "palette.h"

#define PALOVER_LIST_TERM 0xFF

struct PaletteOverride
{
    u8 slot;
    u8 startHour;
    u8 endHour;
    const u16 *palette;
};

extern u16 ALIGNED(4) gPlttBufferPreDN[PLTT_BUFFER_SIZE];
extern EWRAM_DATA const struct PaletteOverride *gPaletteOverrides[];

u8 GetCurrentTimeOfDay(void);
//u8 GetTimeOfDay(s8 hours);
void LoadCompressedPaletteDayNight(const u32 *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void CheckClockForImmediateTimeEvents(void);
void ProcessImmediateTimeEvents(void);
void FillDNPlttBufferWithBlack(u32 offset, u16 size);
void LoadCompressedPalette_HandleDayNight(const u32 *src, u16 offset, u16 size, bool32 isDayNight);
void LoadPalette_HandleDayNight(const void *src, u16 offset, u16 size, bool32 isDayNight);

#endif // GUARD_DAY_NIGHT_H