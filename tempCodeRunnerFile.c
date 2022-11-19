#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
char Board(int PLayerInput){
    char board[3][3];
    return board[3][3];
}
int main(){
    int winner = 1;
    char board[3][3];
    

    for(int i = 0; i< 3;i++){
        for(int j = 0;j<3;j++){
            board[i][j] = ' ';
        }
    }
   
   int wRow,wColumn;
    const char PLAYER = 'X';

/*
    while( winner == 1){
    do{
    printf("  %c |  %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n ---|----|---|\n");
    printf("  %c | %c  | %c  ",board[2][0],board[2][1],board[2][2]);
    printf("\n");


    printf("Please enter a row: ");
    scanf("%d",&wRow);
    wRow--;
    printf("Please enter a  column ");
    scanf("%d",&wColumn);
    wColumn--;

    if(board[wRow][wColumn] != ' '){
            printf("Invalid move\n");
        }
    else {
            board[wRow][wColumn] = PLAYER;
            break;
        }

    }while(board[wRow][wColumn] != ' ');
    }
*/
}