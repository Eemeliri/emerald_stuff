#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

// the species to force to load if we open from the party menu
extern EWRAM_DATA u16 gSpeciesToLoad;

void CB2_OpenPokedexPlusHGSS(void);
void Task_DisplayCaughtMonDexPageHGSS(u8);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
