#ifndef _E_FTRACK_H_
#define _E_FTRACK_H_


list_t flags;
extern char *flagtrack_statusbar;

void Cmd_Drop_Flag(edict_t *player);
edict_t *tossFlag(edict_t *player);
void FlagTrackDeadDropFlag(edict_t *targ, edict_t *attacker);
void FlagTrackScoring(edict_t *targ, edict_t *inflictor, edict_t *attacker);
void FlagTrackEffects(edict_t *player);
void FlagTrackInit();


#endif