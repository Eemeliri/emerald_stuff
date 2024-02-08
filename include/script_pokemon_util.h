#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u32 ScriptGiveMon(u16, u8, u16);
u32 ScriptGiveMonParameterized(u16, u8, u16, u8, u8, u8, u8, u8 *, u8 *, u16 *, bool8, bool8, u8);
u8 ScriptGiveEgg(u16);
void CreateScriptedWildMon(u16, u8, u16);
void CreateScriptedWildMon2(u16, u8, u16, u8, u16, u16, u16, u16, bool8);
void CreateScriptedDoubleWildMon(u16, u8, u16, u16, u8, u16);
void ScriptSetMonMoveSlot(u8, u16, u8);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);
u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8* evs, u8* ivs, u16* moves, bool8 isShiny);
void Script_GetChosenMonOffensiveEV(void);
void Script_GetChosenMonDefensiveEV(void);
void Script_GetChosenMonOffensiveIV(void);
void Script_GetChosenMonDefensiveIV(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
