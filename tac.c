/*
Need what?
->> player,winner,loser,computer
->> board,turns(do while)
->> 
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// prints the main 3x3 board
// affected by ResetBoard() , CheckFreeSpaces() ,  UserInput(), ComInput();
void Board(int PtrBoard){
    int board[3][3];
    printf("  %c |  %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c  ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
// get data from UserInput() and ComInput() and sent to Board();
void PtrBoard(int *PlayerRow,int *PlayerColumn){
    int board[3][3];
}
// runs first ; reset Board();
void ResetBoard(int board[3][3]){
    int wboard[3][3];
    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
         board[i][j] = ' ';
        }
    }
}
// affected by GameCondition
int StartGame(bool(*GameCondition)(int));
//affected by ResetBoard() , Board();
int checkFreeSpaces();

// get data from main() , data from main() pass to UserInput(), 
// UserInput() pass to int PtrBoard();
void UserInput(int *const PlayerRow,int *const PlayerColumn){
    int *wboard[3][3];
    const char PLAYER = 'X';
    
    do{
    /*
    *PlayerRow -= 1;
    *PlayerColumn -= 1;
    */
    if(wboard[*PlayerRow][*PlayerColumn] != ' '){
        puts("error");
    }
    else{
        wboard[PlayerRow][PlayerColumn] = PLAYER;
    }

    }while(wboard[PlayerRow][PlayerColumn]);
}
int ComInput(int const *ComRow,int const *ComColumn);
int main(){

    // 0 == win , 1 == Lose , 2 == Draw ;
    int GameStatus = 1;
    int row,col;

    if(GameStatus == 0){
        puts("You win!");
        return 0;
    }

    else{
        while(GameStatus != 0){
          printf("Please enter a row: ");
          scanf("%d",&row);
          row--;
          printf("Please enter a  column ");
          scanf("%d",&col);
          col--;

          UserInput(&row,&col);
           
        }
    }
}