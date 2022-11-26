#include <stdio.h>
#include "map.h"
#include "scoreboard.h"

void SAVESCOREBOARD (Map *mapGame, int skor){ // ini tapi belum masuk ke file konfigurasi
    printf("Nama: ");
    char *nama;
    nama = scaninput();
    while (IsMemberMap(*mapGame,nama)){
        printf("Nama sudah terpakai silahkan pilih nama lain\n");
        printf("Nama: ");
        nama = scaninput();
    }
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

void PrintScore (Map scoreboard, char *nama){
    printf("**** SCOREBOARD GAME %s ****\n",nama);
    printf("| NAMA\t\t | SKOR \t\t |\n");
    printf("|----------------------------------------|\n");
    Map temp;
    temp = CopyMap(&scoreboard);
    int totalskor = scoreboard.Count;
    if (totalskor > 0){
        for (int i = 0; i<totalskor;i++){
            int idxmax;
            idxmax = IMAX(&temp);
            printf("| %s\t\t | %d \t\t\t |\n",temp.Elements[idxmax].Key,temp.Elements[idxmax].Value);
            DeleteMap(&temp,temp.Elements[idxmax].Key);
        }
    }
    else{
        printf("---\t     SCOREBOARD KOSONG\t       ---\n");
    }
    printf("\n");
}
void SCOREBOARD (TabMap arrscore, ArrayDin listgame){
    // LOOPING DARI PRINTSCORE
    for (int i=0;i<NbElmtArrMap(arrscore);i++){
        PrintScore(arrscore.TIMap[i],listgame.A[i]);
    }
}


char* numToString(int val){
    if(val==0){
        return "0";
    }
    else{
         static char buf[32] = {0};
        int i = 30;
        for(; val && i ; --i, val /= 10)
            buf[i] = "0123456789abcdef"[val % 10];
        return &buf[i+1];
    }
}


// int main(){
//     Map coba;
//     CreateEmptyMap(&coba);
//     InsertMap(&coba,"BNMO",12);
//     int skor = 10;
//     SAVESCOREBOARD(&coba,skor);
// }