#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "map.h"
#include <stdio.h>

void SAVESCOREBOARD (Map *mapGame, int skor); // ini tapi belum masuk ke file konfigurasi

int IMAX (Map *map);

Map CopyMap (Map *map);

void SCOREBOARD (Map *mapTOH, Map *mapDinner, Map *mapSnake, Map *mapRNG, Map *mapHangman);

#endif