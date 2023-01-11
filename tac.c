#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#define BoardColumn 3
#define BoardRow 3
#define PLAYER 'X'
#define COMPUTER 'O'
void Board(int BoardChange,int *PlayerMove[][0],int *ComputerMove){
    char MainBoard[BoardRow][BoardColumn];
    if(*PlayerMove != " ");
    printf("  %c | %c  | %c  |",MainBoard[0][0],MainBoard[0][1],MainBoard[0][2]);
    printf("\n -------------\n");
    printf("  %c | %c  | %c  |",MainBoard[1][0],MainBoard[1][1],MainBoard[1][2]);
    printf("\n -------------\n");
    printf("  %c | %c  | %c  |",MainBoard[2][0],MainBoard[2][1],MainBoard[2][2]);
    printf("\n");
}
// runs second - reset the board in void Board();
int ResetBoard(){
    void Board(int BoardChange,int *PlayerMove[][0],int *ComputerMove);
    char wboard[4][4];
    for(int RowCount=0; RowCount<2; RowCount++){
        for(int ColumnCount=0; ColumnCount<2; ColumnCount++){
          wboard[BoardRow][BoardColumn] = ' ';
        }
    }
    Board(wboard[BoardRow][BoardColumn],0,0);
    return 0;
}
// affected by GameCondition
int StartGame(bool(*GameCondition)(int));

// get data from main() ,the data from main() pass to UserInput(), 
// UserInput() pass to int PtrBoard();
void UserInput(){
   void Board(int BoardChange,int *PlayerMove[][0],int *ComputerMove);
    // pass 2 set of data from UserInput() to PassBoard()
    int Passboard[3][3];
    int PtrPlayerRowInput,PtrPlayerColInput;
    printf("Please enter a row: ");
    scanf("%d",&PtrPlayerRowInput);
    PtrPlayerRowInput--;
    printf("Please enter a  column ");
    scanf("%d",&PtrPlayerColInput);
    PtrPlayerColInput--;
    printf("Player has inputted X on (%d,%d)\n",PtrPlayerRowInput,PtrPlayerColInput);
    Passboard[PtrPlayerRowInput][PtrPlayerColInput] = PLAYER;
   
   Board(0,&Passboard[PtrPlayerRowInput][PtrPlayerColInput],0);
}
int ComInput(int const *ComRowGenerate,int const *ComColumnGenerate);
int main(int argc, char **argv){

    // 0 == win , 1 == Lose , 2 == Draw ;
    int GameStatus = 1;
    int UserInputRowMain,UserInputColMain;
   ResetBoard();
   Board(0,0,0);

    while(GameStatus != 0){

    UserInput();
    }
    puts("You win!");
    return 0;
}