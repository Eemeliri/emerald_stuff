#ifndef GUARD_GTS_MENU_H
#define GUARD_GTS_MENU_H

u16 GetGTSBaseBlock(void);
void CB2_MysteryGiftEReader(void);
void PrintGTSTopMenu(bool8 isJapanese, bool32 usePickOkCancel);
void GTS_DrawCheckerboardPattern(u32 bg);
void MainCB_GTSFreeAllBuffersAndReturnToInitTitleScreen(void);
bool32 PrintGTSMenuMessage(u8 *textState, const u8 *str);
void GTSAddTextPrinterToWindow1(const u8 *src);
void CB2_InitEReader(void);
void CB2_InitGlobalTradeStation(void);
void GTS_DrawTextBorder(u8 windowId);
s8 DoGTSYesNo(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str);

#endif // GUARD_GTS_MENU_H