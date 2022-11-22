#include <stdio.h>
#include "map.h"
#include "scoreboard.h"

void SAVESCOREBOARD (Map *mapGame, int skor){ // ini tapi belum masuk ke file konfigurasi
    printf("Nama: ");
    char *nama;
    nama = scaninput();
    InsertMap(mapGame,nama,skor);
}

int IMAX (Map *map){
    int imax;
    imax = 0;
    for (int i = 1 ; i<map->Count ; i++){
        if (map->Elements[i].Value > map->Elements[imax].Value){
            imax = i;
        }
    }
    return imax;
}

Map CopyMap (Map *map){
    Map temp;
    CreateEmptyMap(&temp);
    for (int i = 0;i<map->Count;i++){
        InsertMap(&temp,map->Elements[i].Key,map->Elements[i].Value);
    }
    return temp;
}

void SCOREBOARD (Map *mapTOH, Map *mapDinner, Map *mapSnake, Map *mapRNG, Map *mapHangman){
    // SCOREBOARD GAME TOWER OF HANOI 
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map tempTOH;
    tempTOH = CopyMap(mapTOH);
    int sumTOH = mapTOH->Count;
    if (sumTOH>0){
        for (int i = 0; i<sumTOH;i++){
            int idxTOH;
            idxTOH = IMAX(&tempTOH);
            printf("| %s\t\t | %d \t\t\t |\n",tempTOH.Elements[idxTOH].Key,tempTOH.Elements[idxTOH].Value);
            DeleteMap(&tempTOH,tempTOH.Elements[idxTOH].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");


    // SCOREBOARD GAME DINNER DASH
    printf("**** SCOREBOARD GAME DINNER DASH ****\n");
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map tempDinner;
    tempDinner = CopyMap(mapDinner);
    int sumDinner = mapDinner->Count;
    if (sumDinner>0){
        for (int i = 0; i<sumDinner;i++){
            int idxDinner;
            idxDinner = IMAX(&tempDinner);
            printf("| %s\t\t | %d \t\t\t |\n",tempDinner.Elements[idxDinner].Key,tempDinner.Elements[idxDinner].Value);
            DeleteMap(&tempDinner,tempDinner.Elements[idxDinner].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");


    // SCOREBOARD GAME SNAKE ON METEOR
    printf("**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map tempSnake;
    tempSnake = CopyMap(mapSnake);
    int sumSnake = mapSnake->Count;
    if (sumSnake>0){
        for (int i = 0; i<sumSnake;i++){
            int idxSnake;
            idxSnake = IMAX(&tempSnake);
            printf("| %s\t\t | %d \t\t\t |\n",tempSnake.Elements[idxSnake].Key,tempSnake.Elements[idxSnake].Value);
            DeleteMap(&tempSnake,tempSnake.Elements[idxSnake].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");


    // SCOREBOARD GAME RNG
    printf("**** SCOREBOARD GAME RNG ****\n");
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map tempRng;
    tempRng = CopyMap(mapRNG);
    int sumRNG = mapRNG->Count;
    if (sumRNG>0){
        for (int i = 0; i<sumRNG;i++){
            int idxRNG;
            idxRNG = IMAX(&tempRng);
            printf("| %s\t\t | %d \t\t\t |\n",tempRng.Elements[idxRNG].Key,tempRng.Elements[idxRNG].Value);
            DeleteMap(&tempRng,tempRng.Elements[idxRNG].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");


    // SCOREBOARD GAME HANGMAN
    printf("**** SCOREBOARD GAME HANGMAN ****\n");
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map tempHangman;
    tempHangman = CopyMap(mapHangman);
    int sumHangman = mapHangman->Count;
    if (sumHangman>0){
        for (int i = 0; i<sumHangman;i++){
            int idxHangman;
            idxHangman = IMAX(&tempHangman);
            printf("| %s\t\t | %d \t\t\t |\n",tempHangman.Elements[idxHangman].Key,tempHangman.Elements[idxHangman].Value);
            DeleteMap(&tempHangman,tempHangman.Elements[idxHangman].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");

}


// int main(){
//     int skor = 12;
//     Map coba,dinner,snake,rng,hangman;
//     CreateEmptyMap(&coba);
//     CreateEmptyMap(&dinner);
//     CreateEmptyMap(&snake);
//     CreateEmptyMap(&rng);
//     CreateEmptyMap(&hangman);
//     SAVESCOREBOARD(&coba,skor);
//     SCOREBOARD(&coba,&dinner,&snake,&rng,&hangman);
//     return 0;
// }