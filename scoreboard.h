#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "map.h"
#include "arrayMap.h"
#include "arraydin.h"
#include <stdio.h>

void SAVESCOREBOARD (Map *mapGame, int skor); // ini tapi belum masuk ke file konfigurasi

int IMAX (Map *map);

Map CopyMap (Map *map);

void PrintScore(Map map, char *nama);

void SCOREBOARD (TabMap arrscore, ArrayDin listgame);

char* numToString(int val);

void SAVESCORE(Map mapGame,FILE * txt);

#endif