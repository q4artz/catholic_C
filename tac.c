/*
Need what?
->> player,winner,loser,computer
->> board,turns(do while)
->> 
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
void Board(){
    int board[3][3];
    printf("  %c |  %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c  ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int ResetBoard(int board[3][3]){
    int wboard[3][3];
    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
          return board[i][j] = ' ';
        }
    }
}
int StartGame(bool(*GameCondition)(int));
int checkFreeSpaces();
int UserInput(int *const row,int *const column);
int ComInput(int const *row,int const *column);
int main(){

    // 0 == win , 1 == Lose , 2 == Draw ;
    int GameStatus;

    if(GameStatus == 0){
        puts("You win!");
        return 0;
    }

    else{
        if(GameStatus == 1){
           ResetBoard();
           Board();
        }
    }

   
}