#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define BoardColumn 3
#define BoardRow 3
// affected by ResetBoard() , CheckFreeSpaces() ,  UserInput(), ComInput();
void ShowcaseBoard(){
    int ShowcaseBoard[BoardRow][BoardColumn];
    printf("    |   |   |");
     printf("\n");
    printf("    |   |   |");
     printf("\n");
    printf("    |   |   |");
    printf("\n");
}
void Board(int BoardChange){
    char MainBoard[BoardRow][BoardColumn];
    printf("  %c | %c  | %c  |",MainBoard[0][0],MainBoard[0][1],MainBoard[0][2]);
    printf("\n -------------\n");
    printf("  %c | %c  | %c  |",MainBoard[1][0],MainBoard[1][1],MainBoard[1][2]);
    printf("\n -------------\n");
    printf("  %c | %c  | %c  |",MainBoard[2][0],MainBoard[2][1],MainBoard[2][2]);
    printf("\n");
}
// get data from UserInput() and ComInput() and sent to Board();
void PtrBoard(int *PLayerMove){
    int row,col;
    int board[BoardRow][BoardColumn];
    const char PLAYER = 'X';
}
// runs first ; reset Board();
void ResetBoard(){
    void Board(int BoardChange);
    char wboard[BoardRow][BoardColumn];
    for(int RowCount=0; RowCount<3; RowCount++){
        for(int ColumnCount=0; ColumnCount<3; ColumnCount++){
         //wboard[RowCount][ColumnCount] = ' ';
         Board(wboard[RowCount][ColumnCount] = ' ');
        }
    }
}
// affected by GameCondition
int StartGame(bool(*GameCondition)(int));
//affected by ResetBoard() , Board();
int checkFreeSpaces(bool(*BoardCondition)(int)){
    int Board;
}

// get data from main() , data from main() pass to UserInput(), 
// UserInput() pass to int PtrBoard();
void UserInput(int *const PtrPlayerRowInput,int *const PtrPlayerColInput){
    void PtrBoard(int *PlayerMoveRow);
    void resetBoard();
    // want to pass 2 set of data from UserInput() to PassBoard()
    int Passboard[*PtrPlayerRowInput][*PtrPlayerColInput] = malloc(BoardRow *sizeof(int) & BoardColumn *sizeof(int));
    Passboard[*PtrPlayerRowInput][*PtrPlayerColInput] = 0;
    
    //Passboard was never reset so get error everytime;
    
    do{
    if(Passboard[*PtrPlayerRowInput][*PtrPlayerColInput] != ' '){
        puts("Player Input Error");
    }
    else{
        PtrBoard(&Passboard[*PtrPlayerRowInput][*PtrPlayerColInput]);
    }
    }while(Passboard[*PtrPlayerRowInput][*PtrPlayerColInput]);
}
int ComInput(int const *ComRowGenerate,int const *ComColumnGenerate);
int main(int argc, char **argv){

    // 0 == win , 1 == Lose , 2 == Draw ;
    int GameStatus = 1;
    int UserInputRowMain,UserInputColMain;
    ShowcaseBoard();

    if(GameStatus == 0){
        puts("You win!");
        return 0;
    }
    ResetBoard();
    while(GameStatus != 0){
    printf("Please enter a row: ");
    scanf("%d",&UserInputRowMain);
    UserInputRowMain--;
    printf("Please enter a  column ");
    scanf("%d",&UserInputColMain);
    UserInputColMain--;

    UserInput(&UserInputRowMain,&UserInputColMain);
    Board(0);
    }
}