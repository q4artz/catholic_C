/* Potential bugs
    - animals that sliped below 0 should not display negative integer
        - able to fix by adding a function that checks it?
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define track 70

int Hare(int *HarePosition);
int Tortoise(int *TortoisePosition);
int GameCondition(int *HarePosition,int *TortoisePosition);

int main(int argc,char *argv[]){
    int TortoisePosition=0,HarePosition=0,clock=0,Condition=0;
    srand(time(NULL));

    puts("Race Start!!\n");

   do{
        // count the amount of turns
        ++clock;
        printf("\nTime is now %d !!\n",clock);

        // Position is initialized to 0 and pass to Their own functions 
        HarePosition = Hare(&HarePosition);
        TortoisePosition = Tortoise(&TortoisePosition);

        // checks if any of the animals has gone over 70
        Condition = GameCondition(&HarePosition,&TortoisePosition);
    }while(Condition == 0);

   if(Condition == 1)
        puts("Hare won");
   if(Condition == 2)
    puts("Tortoise won");
    
return 0;
}

int Hare(int *HarePosition){
    int Haremove =0;
    int hare = *HarePosition;
    Haremove = rand() % 10+1;
    if(hare < 0)
        hare =0;
   if (Haremove >= 3 && Haremove <= 4){
       hare += 9;
       puts("Hare Hopped 9 squares!!!");
   }
   else if(Haremove == 5){
       hare -= 12;
       puts("Hare Sliped 12 squares!!");
   }
   else if( Haremove >= 6 && Haremove <= 8){
       hare += 1;
       puts("Hare Hopped 1 squares!!");
   }
   else if(Haremove >= 9 && Haremove >= 10){
       hare -= 2;
       puts("Hare Sliped 2 squares!!");
   }
   else 
       puts("hare Slept?????");
   printf("Hare is now at %d!\n",hare);
    return hare;
};
int Tortoise(int *TortoisePosition){
    int tortoise = *TortoisePosition;
    int TortoiseMove = 0;
    if(tortoise < 0)
        tortoise = 0;
    TortoiseMove = rand() % 10+1;
    if (TortoiseMove >= 1 && TortoiseMove <= 5){
        tortoise += 3;
        puts("Tortoise plod 3 squares!!");
    }
    else if(TortoiseMove >= 6 && TortoiseMove <= 7){
        tortoise -= 6;
        puts("Tortoise Sliped 6 squares!!");
    }
    printf("Tortoise is now at %d!\n",tortoise); 
    return tortoise;
};
int GameCondition(int *HarePosition,int *TortoisePosition){
    // 0 == ongoing ; 1 == Hare ; 2 == Tortoise
    int GameStatus =0;
    int hare = *HarePosition,tortoise = *TortoisePosition;
     if(hare > 70){
        return 1;
     }
     else if(tortoise > 70){
        return 2;
     }
     else return 0;
};
