#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// affected by ResetBoard() , CheckFreeSpaces() ,  UserInput(), ComInput();
void Board(){
    int MainBoard[3][3];
    printf("  %c |  %c | %c ",MainBoard[0][0],MainBoard[0][1],MainBoard[0][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c ",MainBoard[1][0],MainBoard[1][1],MainBoard[1][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c  ",MainBoard[2][0],MainBoard[2][1],MainBoard[2][2]);
    printf("\n");
}
// get data from UserInput() and ComInput() and sent to Board();
void PtrBoard(int *PLayerMove[],int *ComMove){
    int row,col;
    int board[row][col];
    const char PLAYER = 'X';

}
// runs first ; reset Board();
void ResetBoard(int board[3][3]){
    int wboard[3][3];
    for(size_t RowCount=0; RowCount<3; RowCount++){
        for(size_t ColumnCount=0; ColumnCount<3; ColumnCount++){
         board[RowCount][ColumnCount] = ' ';
        }
    }
}
// affected by GameCondition
int StartGame(bool(*GameCondition)(int));
//affected by ResetBoard() , Board();
int checkFreeSpaces();

// get data from main() , data from main() pass to UserInput(), 
// UserInput() pass to int PtrBoard();
void UserInput(int *const PlayerRowInput,int *const PlayerColumnInput){
    void PtrBoard(int *PlayerRow[],int *PlayerColumn);
    int Passboard[3][3];
    
    do{
    /*
    *PlayerRow -= 1;
    *PlayerColumn -= 1;
    */
    if(Passboard[*PlayerRowInput][*PlayerColumnInput] != ' '){
        puts("Player Input Error");
    }
    else{
        PtrBoard(&Passboard[*PlayerRowInput][*PlayerColumnInput]);
    }

    }while(Passboard[*PlayerRowInput][*PlayerColumnInput] );
}
int ComInput(int const *ComRowGenerate,int const *ComColumnGenerate);
int main(){

    // 0 == win , 1 == Lose , 2 == Draw ;
    int GameStatus = 1;
    int UserInputRowMain,UserInputColMain;
    void Board();

    if(GameStatus == 0){
        puts("You win!");
        return 0;
    }

    else{
        ResetBoard();
        while(GameStatus != 0){
          printf("Please enter a row: ");
          scanf("%d",&UserInputRowMain);
          UserInputRowMain--;
          printf("Please enter a  column ");
          scanf("%d",&UserInputColMain);
          UserInputColMain--;

          UserInput(&UserInputRowMain,&UserInputColMain);
           
        }
    }
}