// Chapter 10 C structures , Unions, Bit Manipulation, Enumerations

// 10.2 Structure Defitnition
/*
Struct are related variables under one name
((may contain same or different variables))
example 
struct employees{
    char firstName[20];
    char lastName[20];
    unsigned int age;
    char gender;
    double salaryhours;
};
*/

/*
Struct cannot be decleared in another struct unless it is a pointer
example
struct company{
    struct employees teamLeader; // error
    struct employees *PtrTeamLeader; // pointer no error
}
*/

//10.2.2 Defining Variables of structure types
/*
// ((we can declear a variable to the the type of the struct))
// currently idk what it is for but i plan to find out soon
#include <stdio.h>
#include <stdlib.h>
struct card{
    char *face;
    char *suit;
}aCard,deck[52],*cardPtr;
*/

// 10.3 Initailiing Structure
/*
#include <stdio.h>
#include <stdlib.h>
struct card{
    // initialize what each struct should have inside
    char *face;
    char *suit;
}aCard,deck[52],*cardPtr; // initailize what variable should hold the struct
struct card aCard = {
    // initializing the struct 
    // the face from *face now is Three in aCard
    "Three",
    // the *suit from *suit now is Hearts in aCard
    "Hearts"
};
int main(){
    printf("%s\n",aCard.suit);
}
*/

// 10.4 Accessing Structure Members with . and -> 
/*
(.) is the structure number operator
    - access struct member via struct variable name
    - like printf("%s\n",aCard.suit);
(->) is the structure pointer operator/ arrow operator (used this in js alot)
    - pointer 
*/

/*
#include <stdio.h>
struct card{
    char *face;
    char *suit;
};

int main(){
    struct card aCard;
    
    aCard.face="Ace";
    aCard.suit="Spades";

    struct card *cardPtr = &aCard;
    printf("%s%s%s\n%s%s%s\n%s%s%s\n",
    aCard.face,"of",aCard.suit,cardPtr->face,"of",cardPtr->suit,
    (*cardPtr).face,"of",(*cardPtr).suit);
}
*/

// 10.5 Using Structures with Functions

/*
Structure can only be pass to function by
    - Individual structure members
        - passed by value
    - entire structure
    - pointer to a structure

    - Arrays are passed by reference
*/

// 10.6 typedef ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// typedef replace the Data type with the variable name
// so like typedef int Student
// you can call Student and it will represent int

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char Name[50];
    char Gender;
}Student;

int main(){

    Student James;

}
*/

// using Struct in a function -------------------------------------------

/*
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// typedef require us to only declear main structure one time
typedef struct {
    char Name[30];
    char id[10];
    int age;
    int grade[5];
}Student;

void Printing_student(Student student){
    printf("Name is %s\n",student.Name);
    printf("ID is %s\n",student.id);
    printf("Age is %d\n",student.age);
    printf("Grades is ");
    for(int i=0;i<=5;i++){
        printf("\n%d",student.grade[i]);
    };
}
int main(){
    // we then can use the decleared struct to assign to other struct
    Student James;

    strcpy(James.Name,"Jamess");
    strcpy(James.id,"0120312");
    James.age = 12;
    for (int grade=1;grade<=5;grade++)
        James.grade[grade] = grade;
    
    
    Printing_student(James);
}
*/

// another way to declear structure members

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}Pointing;

int main(){
    // declear struct in curly braces
    Pointing p1 = {4,6};

    // or we can write out the full thing 
    Pointing p2 = {.x=10,.y=20};
}
*/

// Array structures 

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}Pointing;

int main(){
    Pointing point[10];

    for (int i=0;i<10;i++){
        point[i].x = i;
        point[i].y = i-1;
    }
    for(int i=0;i<10;i++){
        printf("p%d =(%d,%d)\n",
        // print the struct point at x's / y's value i 
        i,point[i].x,point[i].y);
    }
}
*/

// Pointer Structure

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *array;
}Pointers;

int main(){
    Pointers One,Two;

    // dynamic alloc mem
    One.array = malloc(sizeof(int)*5);
    Two.array = malloc(sizeof(int)*5);

    One.array[0] = 1;
     One.array[1] = 2;
      One.array[2] = 3;
       One.array[3] = 4;
        One.array[4] = 1;
         One.array[5] = 9;

    Two.array[0] = 9;
     Two.array[1] = 9;
     Two.array[2] = 9;
     Two.array[3] = 9;
     Two.array[4] = 9;
     Two.array[5] = 3;

    // assignment copies the memory of Two.array to One.array
    One.array = Two.array;

    for(int i=0;i<5;i++)
        printf("One array = %d\n",One.array[i]);
    puts("\n");
    for(int i=0;i<5;i++)
         printf("Two array = %d\n",Two.array[i]);
}