// from book how to program C eight edition and youtube

// 7.3 Pointer Operatons ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ very important

// & is an address operator
// * is a dereference/indirection operator

/*
#include <stdio.h>
int main(){
    int y = 5;
    int *yPtr;
    yPtr = &y; // this yPtr variable has the address of y
    printf("y is %d\n&y is %d\nyPtr is %d\n*yPtr is %d\n",y,&y,yPtr,*yPtr);
    // y get 5
    // &y get the mem address of y
    // yPtr get mem address of y
    // *yPtr get 5
}
*/

/* RECAP ~ because we assign yPtr to the address of y, when we use the dereference operator *,
 the *yPtr dereference(decrypt) the mem address which return 5 (the value y)*/

/*
#include <stdio.h>
int main(){
    {
    int b = 5;
    int *a = &b;

    printf("the b value is %d\n",b);
    printf("the &b value is %d\n",&b);
    printf("the a value is %d\n",a);
    printf("the *a value is %d\n",*a);
    printf("the &a value is %d\n",&a);
    }

    {
        // the *a points to the address of b and modifying the value
        // the address of a is the same as b

        // *a is like a vector he impersonate b taking anything thrown
        // at him and pass the thing to b
        int b = 5;
        int *a = &b;
        *a = 50;

        printf("\n\n");
        printf("when *a is set to 50 we get \n");
        printf("the b value is %d\n",b);
        printf("the &b value is %d\n",&b);
        printf("the a value is %d\n",a);
        printf("the *a value is %d\n",*a);
        printf("the &a value is %d\n",&a);
    }

    {
        int b = 5;
        int *a = &b;
        a = 10;

        printf("\n\n");
        printf("when a is set to 10 we get\n");
        printf("the b value is %d\n",b);
        printf("the &b value is %d\n",&b);
        printf("the a value is %d\n",a);
        printf("the *a value is %d\n",*a);
        printf("the &a value is %d\n",&a);
    }
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~  %p is printing for a pointer address ~~~~~~~~~~~~~~~~~~~~~~//
/*
 #include <stdio.h>
 int main(){
    int a =7;
    int *aPtr = &a;

    printf("The address of a is %p"
    "\nThe Value of aPtr os %p",&a,aPtr);

    printf("\n\nThe value of a is %d"
    "\nThe alue of *aPtr is %d",a,*aPtr);

    printf("\n\nShowing that * and & are complements of "
    "each other\n&*aPtr = %p"
    "\n*&aPtr = %p \n",&*aPtr,*&aPtr);
 }
*/

// 7.4 Passing Arguement to Functions by Reference ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* there are two ways to pass arguements to a function 
->> pass by value
-- all arguements in C are passed by value
->> pass by reference
*/

/* pass by value */

/*
#include <stdio.h>

int cubeByValue(int n);
int main(){
    int number = 5;

    printf("The original value of number is %d",number);

    // pass number by value to cubeByValue
    number = cubeByValue(number);

    printf("\nThe new value of number is %d\n",number);
}
// calculate and return cube of integer arguement
int cubeByValue(int n){
    return n * n * n; //cube local variable n and return result 
}
*/

/*
#include<stdio.h>

void cubeByReference(int *nPtr);
int main(){
    int number = 5;

    printf("The original value of number is %d",number);

    // pass address of number to cubeByReference
    cubeByReference(&number);

    printf("\n the new value of number is %d\n",number);
}
// calculate cube of *nPtr; actually modifies number in main
void cubeByReference(int *nPtr){
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}
*/

// hw ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
#include <stdio.h>
int reference(int *i);
int whileloop(int *o);
int passtoA(int *b);
int main(){
    {
    int j = 5;

    printf("the value of j is %d\n",j);

    reference(&j);

    printf("the new value of j is %d\n",j);
    }
    {
        int o = 10;
        printf("\n\n");
         printf("the value of o is %d\n",o);

         whileloop(&o);

         printf("the new value of o is %d\n",o);
    }
    {
        int a = 2;
        int *b = &a;

        printf("\n\n");
        printf("the value of a is %d\n",a);
        printf("the address of &a is %d\n",&a);
        printf("the address of *b is %d\n",*b);

        passtoA(&a);

        printf("\n\n");
        printf("the new value of a is %d\n",a);
        printf("the address of &a is %d\n",&a);
        printf("the address of *b is %d\n",*b);
    }
}
int reference(int *i){
    for(*i = 1; *i <= 15;){
        *i += *i ;
    }
    return *i;
}
int whileloop(int *k){
    while(*k < 20){
        *k += 1;
    }
    return *k;
}
int passtoA(int *b){
    return *b += *b;
}
*/

// !!!! More Function pointers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// PASS BY VALUE FUNCTION POINTER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
#include<stdio.h>
int add(int a,int b);
int main(){
    int result;
    int (*Ptr)(int,int) = &add;
    result = (*Ptr)(10,20);
    printf("the value of a plus b is %d\n",result);
}
int add(int a,int b){
    return a + b;
}
*/

// PASS BY VALUE ARRAY FUCNTION POINTER ~~~~~~~~~~~~~~~~~~~~~~~~~~
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NOT COMPLETE
#include <stdio.h>
int arr(int i);
int main(){
    int result;
    // we put () around the *Ptr so it has more priority than [5] array
    int (*Ptr)[5];
    result = (*Ptr[5]);
    for (int j = 0 ;j <= 5; j++){
    printf("array is now %d\n",result);
    }
}
int arr(int i){
    for (i=0;i<=5;i++){
        i += i;
    }
    return i;
}
*/

// allocating memory space for an array length determided by user
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *a;
    int length = 0;

    printf("enter a length\n");
    scanf("%d",&length);

    // malloc allocate memory to the condition
    a = malloc(length *sizeof(int));
    for (int i = 0; i< length; i++){
    printf("a before : %d\n",a);
        a[i] = i;
    }
    for (int i=0;i<length;i++)
        printf("a[%d] = %d\n",i,a[i]);

    free(a);
}
*/

//
// 7.5 Using the const Qualifier with pointers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 7.5.1 Converting a String to uppercase with ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Non const pointer to a non const data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
->> granted highest level of data access 
->> data can be modified through dereference pointer 
->> pointer can be modified to point to other data items
->> doesnt include const
---------------------  USES -----------------------------------
->> recieve a string as argument to func to process
*/

/*
#include<stdio.h>
#include<ctype.h>
void convertToUppercase(char *sPtr);
int main(){
    char string[] = "cHaRaCters and $32.98";

    printf("the string before conversion is %s",string);
    // rmb no = is no &, got = use &
    convertToUppercase(string);
    printf("\n the string after conversion is : %s\n",string);
}

//converting string to uppercase letters
void convertToUppercase(char *sPtr){
    while(*sPtr != '\0'){  //current character is not '\0'
        *sPtr = toupper(*sPtr); // convert to uppercase
        ++sPtr; // make sPtr point to the next pointer
    }
}
*/

// 7.5.2 Non Constant Pointer to Constant Data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
->> pointer can point any data of appropriate type 
->> data being pointed cannot be modified
-------------------- USES -------------------------------
->> recieve an array argument to a func that will process 
        but not modify the data/element
->> passing data(as reference) in structure to a function
    to reduce execution time overhead (not copy each data one by one)
    ->> by this we had pointers to constant data to get the performance of pass-
        by-reference and the protection of pass-by-value
*/

/*
#include <stdio.h>
// !!!! reads from right to left *sPtr is a char const
// sPtr is a pointer to a character constant
void printCharacter(const char *sPtr);
int main(){
    char string[] = "print charcter of a string";

    puts("The string is: ");
    printCharacter(string);
    puts("");
}
void printCharacter(const char *sPtr){
    // for loop no initialization cus we 
    // dont want to modify the element/data
    for(; *sPtr != '\0'; ++sPtr){ 
        printf("%c",*sPtr);
    }
}
*/

// useful resource to understand 
// int const *ptr  &&  int * const ptr

// 7.5.3 Constant Pointer to Non Constant Data

/*
->> always points to the same memory location
->> data at the location can be modify through pointer
->> POINTER MUST be INITIALIZE when defined
-------------------- USES ------------------------------------
->> receive an array as an argument to a function
    that accesses array elements using only array 
    index notation
*/

/*
#include <stdio.h>
int main(){
    int x,y;

    // ptr is const pointer to an interger that can be modifired
    // thorugh ptr, but ptr always points to the same memory location
    int * const ptr = &x;

    *ptr = 7; // allowed: *ptr is not const
    ptr = &y; // error: ptr is const; cannot assign new address
}
*/

// 7.5.4 Try to modify Constant Pointer to Constant Data

/*
->> least access privilage 
->> pointer always points to the same memory location
----------------------- USES --------------------------------
->> how an array should be passed to a 
    function that only looks at the array
    using array index notation and
    does not modify the array
*/

/*
#include <stdio.h>
int main(){
    int x = 5,y;

    const int * const ptr = &x; //initialization is OK

    printf("%d\n",*ptr);
    *ptr = 7; // error: *ptr is const; cannot assign nerw value
    ptr = &y; // error: ptr is const; cannot assign new address
}
*/

// Extra const pointer ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IMPORTANT

// https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant

// const to a pointer and pointer to a const

/*
#include <stdio.h>
int main(){

    int a = 5;
    int b = 10;

    //CANNOT change what the pointer is pointing to
    //CAN change the value
    int *const constant_pointer = &a;

    //CAN
    *constant_pointer = 10;

    //CANNOT
    // constant_pointer = &b;
    
    //CAN change what the pointer is pointing to
    //CANNOT change the value
    int const *pointer_to_constant_data = &a;

    //CANNOT
    // *pointer_to_constant_data = 10;

    //CAN
    pointer_to_constant_data = &b;
}
*/

// SUMMARY

//                                      Pointer           Value
// Non-Const Pointer To Non-Const >>    Mutable           Mutable
//
// Non-Const Pointer To Non-Const >>    Mutable           Immutable
//
// Const Pointer To Non-Const >>        Immuutable        Mutable
//
// Const Pointer To Const >>           Immutable          Immutable