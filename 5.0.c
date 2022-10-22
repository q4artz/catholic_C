// from book how to program C eight edition and youtube

// 5.5.1 square function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~semi-important

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

// hw @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMPLETED
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

// 5.5.2 maximum function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~semi-important

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

// 5.11 enum ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ important

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

// hw @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Not complete

// write a program require user to enter 2 number that will be sum and comapare by a randomly generated value, if correct win

/* need what?? 
->> srand rand for generating random num
->> enum value to display win lose continue
->> fucntion to store the random num
->> do while loop to repeat user enter number
->> variable for num1 num2 total, random num
*/

/*
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
*/

// 5.12 Storage class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~important
/* there are 4 types of storage class, 
~~~~~~ storage duration is the period during which the identifier exist in memory
->> some exist briefly
->> some are repeatdly created and destroy
->> some exist for the program's entire execution

~~~~~~ identifier's scope is the identifier can be referenced in a program 
->> some can only in a portion of program 
->> some can use throughout the program

~~~~~~ linkage determines for a multiple-source program whether the identifiers is
->> only known in current source file
->> in any source file with proper declearations
*/

/* Static storage class
~~~~~~ local variable with the keyword static only knows in the fucntion they are defined in
~~~~ static variable retain their their value when the function is exited 
*/

// 5.13 Scope Rules ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x=1; //global variable

int main(void){
    int x=5; //local variable to main

    printf("local x in outer scope of main is %5d\n",x);

    { // start of a new scope
        int x=7;

        printf("local x in inner scpoe of main is %5d\n",x);
    } // end of a new scope

    printf("local x in outer scpoe of main is %5d\n",x);

    useLocal(); // useLocal has automatic local x
    useStaticLocal(); // useStaticLocal has static local x
    useGlobal(); // useGlobal uses global x

    useLocal(); //useLocal reinitializes automatic local x
    useStaticLocal(); //static local x retian sits prior value
    useGlobal(); // global x also retains its value

    printf("\nlocal x in main is %5d\n",x);
}
// useLocal reinitializes local variable x during each call
void useLocal(void){
    int x=25; //initialized each time useLocal is called

    printf("\nlocal x in uselocal is %5d after entering useLocal\n",x);
    ++x;
    printf("local x in uselocal is %5d before exiting useLocal\n",x);
}

//useStaticLocal initializes static local variable x only the first time
//the function is called; vlaue of x is saved between calls to this func
void useStaticLocal(void){
    static int x = 50;

     printf("\nlocal x in useStaticlocal is %5d after entering useLocal\n",x);
    ++x;
    printf("local x in useStaticlocal is %5d before exiting useLocal\n",x);
}
// func useGlobal modifies global vairable x during each call
void useGlobal(void){
     printf("\nlocal x in useGlobal is %5d after entering useLocal\n",x);
    x *= 10;
    printf("local x in useGlobal is %5d before exiting useLocal\n",x);
}
