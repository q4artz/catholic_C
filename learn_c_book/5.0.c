// from book how to program C eight edition and youtube

// 5.5.1 square function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
#include <stdio.h>
#include <stdlib.h>
int square(int y); // function prototype
int main(){
    for(int y = 1; y<= 10; ++y){
        printf("%d\n",square(y)); // function call
    }
    return 0;
}
int square(int y){ // need the correct data type to in the parameter and specifier
    return y * y; // this returns the data
}
*/

// hw @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// return double foo in function prototype and print it with do while loop

/*
#include <stdio.h>
#include <stdlib.h>
double proto(double foo); // function prototype
int main(){
    int x = 1;
    do{
        printf("%5.2lf\n",proto(x));
        x++;
    }while(x <= 20);
    return 0;
}
double proto(double foo){
    return foo * foo;
}
*/

// 5.5.2 maximum function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
#include <stdio.h>
#include <stdlib.h>
int maximum(int x,int y,int z);
int main(){
    int number1,number2,number3;
    printf("enter three numbers > ");

    scanf("%d%d%d",&number1,&number2,&number3);

    printf("Maximum number is %d \n",maximum(number1, number2, number3)); 
    // the first number will replace x, the second number will replace y, the third number will replace z
}
int maximum(int x,int y,int z){
    int max = x;
    if(y > max){
        max = y;
    }
    if(z > max){
        max = z;
    }
    return max; //in line 49 printf maximum function will return the max;
}
*/

// 5.11 enum ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ important

/*
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
enum Status {CONTINUE,WON,LOST};

//  Enums are sets of integer constants represented by identifiers
//  Values in enum starts with 0 then 1 and 2 and 3,
//  so CONTINUE has the value of 0 and WON has 1 and LOST has 2

int rollDIce(void);
int main(){
    srand(time(NULL));

    int myPoint;
 // enum status can have CONTINUE / WON or LOST
    enum Status gameStatus; 
 // first part of program executed
    int sum = rollDIce();
    //int sum is equal to the return value of rollDice();

    switch(sum){
        // wins on first roll
        case 7:
        case 11:
        gameStatus = WON;
        break;

        // lost on first roll
        case 2:
        case 3:
        case 12:
        gameStatus = LOST;
        break;

        //remember the number 
        //(did not get any number in case)
        default:
        //game keeps running
        gameStatus = CONTINUE; 
        //set the number rolled to the new requirement to win
        myPoint = sum; 
        printf("Point is %d\n",myPoint);
    }

    //if player did not win or lose
    while(CONTINUE == gameStatus){ 
        //execute roll again and check if number is same as myPoint
        sum = rollDIce(); 
    
    //if number get is same as myPoint
    if(sum == myPoint){
        //enum return 1
        gameStatus = WON;
    }
    else{
        //if player get 7 then game stop or exit
        if(7== sum){
            gameStatus = LOST;
        }
    }

    //win display win
    if(WON == gameStatus){
        puts("player wins");
    }
    //this happends when user get 7
    else{
        puts("player lost");
        }
    }
}
int rollDIce(void){
    int die1 = 1+(rand() %6);
    int die2 = 1+(rand() %6);

    printf("PLayer rolled %d + %d = %d\n",die1,die2,die1+die2);
    return die1+die2;
}
*/

// hw @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// write a program that require user to enter 2 number that will be sum and comapre by a randomly generated value, if correct win

/* need what?? 
- srand rand for generating random num
- enum value to display win lose continue
- fucntion to store the random num
~ do while loop to repeat user enter number
~ variable for num1 num2 total, random num
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int usernum(int Pnum1,int Pnum2,int *firstnum,int *secondnum);
enum status{WIN,LOST,CONTINUE};
int main(){
    srand(time(NULL));

    enum status gameStatus;
    int numberToWin,total;
    int attempt=1;

   numberToWin = 1 + rand() % 10;

    total = usernum();
    
    if(total == numberToWin){
        gameStatus = WIN;
    }
    else if(attempt <= 5){
        gameStatus = CONTINUE;
    }
    else{
            gameStatus = LOST;
    }

    while(gameStatus == CONTINUE){
        usernum();
        attempt++;
    }
    switch(gameStatus){
        case 0:
        puts("you win");
        break;
        case 1:
        puts("you lost");
        break;
    }
}
int usernum(int Pnum1,int Pnum2,int *firstnum,int *secondnum){
    puts("please enter two numbers");
    scanf("%d%d",&Pnum1,&Pnum2);
    printf("number entered %d + %d = %d\n",Pnum1,Pnum2,Pnum1+Pnum2);
    firstnum = &Pnum1;
    secondnum = &Pnum2;
    return Pnum1 + Pnum2;
}