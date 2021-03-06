//g_pakread.c
#ifndef _G_PAKREAD_H_
#define	_G_PAKREAD_H_

#define MAX_FILES_IN_PACK 4096
#define IDPAKHEADER 0x4b434150 //(('K'<<24)+('C'<<16)+('A'<<8)+'P')
#define PAK_HEADER_SIZE 12
#define PAK_file_SIZE 64 

typedef struct
{
  int ident; // == IDPAKHEADER
  int dirofs;
  int dirlen;
} dpackheader_t; 

typedef struct
{
  char name[56];
  int filepos;
  int filelen;
} dpackfile_t; 

typedef struct
{
  int nfiles;
  dpackfile_t file[MAX_FILES_IN_PACK];
} dpackdir_t; 

typedef struct
{
  FILE *fp;
  char *name;
  dpackheader_t header;
  dpackdir_t dir;
} PAK;

qboolean searchForMapInPakFiles(char *mapName);
qboolean searchForMapInPakFile(PAK *pak, char *mapName);
void PakClose(PAK *pak);

#endif