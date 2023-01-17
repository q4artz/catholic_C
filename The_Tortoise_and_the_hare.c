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
            printf("Hare is now at %d!\n",HarePosition);
        TortoisePosition = Tortoise(&TortoisePosition);
            printf("Tortoise is now at %d!\n",TortoisePosition); 

        // checks if any of the animals has gone over 70
        Condition = GameCondition(&HarePosition,&TortoisePosition);
    }while(Condition == 0);

   if(Condition == 1)
        puts("Hare won");
   else
    puts("Tortoise won");
    
return 0;
}

int Hare(int *HarePosition){
    int Haremove =0;
    int hare = *HarePosition;
    Haremove = rand() % 10+1;
   switch(Haremove){
    case 1:
    case 2:
     puts("hare Slept?????");
    break;
    case 3:
    case 4:
        hare += 9;
        puts("Hare Hopped 9 squares!!!");
    break;
    case 5:
        hare -= 12;
        puts("Hare Sliped 12 squares!!");
    break;
    case 6:
    case 7:
    case 8:
        hare += 1;
        puts("Hare Hopped 1 squares!!");
    break;
    default:
        hare -= 2;
        puts("Hare Sliped 2 squares!!");
   }
    if(hare < 0)
        hare =0;
    return hare;
};
int Tortoise(int *TortoisePosition){
    int tortoise = *TortoisePosition;
    int TortoiseMove = 0;
    TortoiseMove = rand() % 10+1;
    //printf("Rolled %d",TortoiseMove);
    if (TortoiseMove <= 5){
        tortoise += 3;
        puts("Tortoise plod 3 squares!!");
    }
    else if(TortoiseMove <= 7){
        tortoise -= 6;
        puts("Tortoise Sliped 6 squares!!");
    }
    else{
        tortoise -= 1;
        puts("Tortoise Sliped 1 square!!");
    }
    if(tortoise < 0)
        tortoise = 0;
    return tortoise;
};
int GameCondition(int *HarePosition,int *TortoisePosition){
    // 0 == ongoing ; 1 == Hare ; 2 == Tortoise
    int hare = *HarePosition,tortoise = *TortoisePosition;
     if(hare > track){
        return 1;
     }
     else if(tortoise > track){
        return 2;
     }
     else 
        return 0;
};
