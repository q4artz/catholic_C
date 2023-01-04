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

// 10.3 Initailiing Structures
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