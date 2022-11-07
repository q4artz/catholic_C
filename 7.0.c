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
    int length = ;

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
    //CAN change the value !!!!
    int *const constant_pointer = &a;

    //CAN
    *constant_pointer = 10;

    //CANNOT
    // constant_pointer = &b;
    
    //CAN change what the pointer is pointing to
    //CANNOT change the value !!!!
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


// 7.6 Bubble sort with Pass by Reference ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
#include <stdio.h>
#define SIZE 10
                 
                // *const array == data CAN change but memory CANNOT
void bubbleSort(int *const array,const size_t size);

int main(){
    int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};

    puts("Data items in original order");

    for(size_t i =0;i< SIZE; ++i){
        printf("%4d",a[i]);
    }

    bubbleSort(a,SIZE);

    puts("\nData items in ascending order");

    for(size_t i = 0; i < SIZE; ++i){
        printf("%4d",a[i]);
    }
    puts("");
}
void bubbleSort(int *const array,const size_t size)
{
    void swap(int *element1Ptr,int *element2Ptr);

    // loop to control passes
    for(unsigned int pass = 0;pass < size -1; ++pass){
        
        // loop to control passes
        for(size_t j = 0; j<size -1; ++j){
            // swap adjacent elements if they’re out of order
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}
void swap(int *element1Ptr,int *element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
*/

// 7.7 sizeof Operator ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`

/*
->> sizeof is compile-time operator
*/

/*
#include <stdio.h>
#define SIZE 20
size_t getSize(float *ptr); // prototype

int main(void)
{
float array[SIZE]; // create array

printf("The number of bytes in the array is %u"
    "\nThe number of bytes returned by getSize is %u\n",
     sizeof(array) ,getSize(array) );
    }
// return size of ptr
size_t getSize(float *ptr)
{
    return sizeof(ptr);
}
*/

/*
#include <stdio.h>
int main(){
    double real[20];

    // print the whole byte size of array
    printf("%d",sizeof(real));

    //print one byte size of array 
    printf("\n%d\n",sizeof(real[0]));

    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;
    int array[20];
    int *ptr = array;

    printf(" sizeof c = %u\tsizeof(char) = %u"
    "\n sizeof s = %u\tsizeof(short) = %u"
    "\n sizeof i = %u\tsizeof(int) = %u"
    "\n sizeof l = %u\tsizeof(long) = %u"
    "\n sizeof ll = %u\tsizeof(long long) = %u"
    "\n sizeof f = %u\tsizeof(float) = %u"
    "\n sizeof d = %u\tsizeof(double) = %u"
    "\n sizeof ld = %u\tsizeof(long double) = %u"
    "\n sizeof array = %u"
    "\n sizeof ptr = %u\n",
    sizeof c, sizeof(char), sizeof s, sizeof(short), sizeof i,
    sizeof(int), sizeof l, sizeof(long), sizeof ll,
    sizeof(long long), sizeof f, sizeof(float), sizeof d,
    sizeof(double), sizeof ld, sizeof(long double),
    sizeof array, sizeof ptr);
}
*/

// 7.8 Pointer epression and Pointer Arithmetic ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 7.8.3 Adding an Integer to a pointer
/*
->> adding a int to a array pointer is 
   (Memory_Location + int * 4(memory size of int))
*/

/*
#include <stdio.h>
int main(){
    int v[20];
    int *vPtr = v;
    vPtr = &v;
    printf("vPtr is >>      %d\n",vPtr);
    vPtr += 2;
    printf("vPtr += 2 is >> %d\n",vPtr);
    vPtr += 2;
    printf("vPtr += 4 is >> %d\n",vPtr);
    vPtr -= 4;
    printf("vPtr -= 4 is >> %d\n",vPtr);
}
*/

// 7.8.6 subtracting one pointer from another

/*
->> DONOT subtract two pointer that dont refer to elements in the same array

#include<stdio.h>
int main(){
    int arr[10];
    int att[10];
    int *Ptr1 = arr;
    int *Ptr2 = arr;
    int x = Ptr1 - Ptr2;
    printf("%d",x);
}
*/

// 7.8.7 Assigning pointer to one another

/*
->> pointer can assign to another pointer of the SAME TYPE
*/

// pointer to void

/*
->> void pointer cannot be dereferenced
     (precise number of bytes which pointer     
     refers is NOT KNOWN by compiler)
->> cannot assign pointer to pointer if one is VOID
*/

// 7.9 Relationship between Pointers and Arrays ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ IMPORTANT

/*
->> array name can be thought of as a const pointer

        int b[5];
        int *bPtr;

        bPtr = b 
    !!!! is the same as !!!!! 
        bPtr = &b[0]

    they both points to the first element  
->> 
*/

// 7.9.1 Pointer/Offset Notation
/*
->> 
*/

/*
#include<stdio.h>
int main(){
    int b[5];
    int *bPtr;

    bPtr = b;

    printf("%d\n",bPtr);
    // the 3 is the offset of the pointer
    //need () because * has higher priority 
    // if no () then 3 will add to bPtr[0]
    {
    *(bPtr + 3);
    printf("%d\n",bPtr);
    }
    {
        bPtr+3;
        printf("%d\n",bPtr);
    }
}
*/

// 7.9.4 Demonstrating pointer indexing and offsets 

/*
->> comparing array[i] and *arrPtr
*/

/*
#include <stdio.h>
#define ARRAY_SIZE 4
int main(){
    int b[] = {10,20,30,40};
    int *bPtr = b;

    puts("Array b printed with:\nArray index notation");

    for(size_t i =0; i< ARRAY_SIZE; ++i){
        printf("b[%u] = %d\n",i,b[i]);
    }

    puts("\nPointer/offset notation where\n"
            "the pointer is array name");

    for(size_t offset = 0;offset < ARRAY_SIZE; ++offset){
        printf("*(b+%u) = %d\n ",offset,*(b+offset));
    }

    puts("\nPointer index notation");

    for(size_t i = 0;i<ARRAY_SIZE;++i){
        printf("bPtr[%u] = %d\n",i,bPtr[i]);
    }

    puts("\nPointer/offset notation");

    for(size_t offset = 0;offset<ARRAY_SIZE; ++offset){
        printf("*(bPtr + %u) = %d\n",offset,*(bPtr +offset));
    }
}
*/

// 7.9.5 String copying with array and pointers

/*
#include <stdio.h>
#define SIZE 10

void copy1(char *const s1, const char *const s2);
void copy2(char *s1, const char *s2);

int main(){

    char string1[SIZE];
    char *string2 = "Hello";

    copy1(string1,string2);
    printf("string1 = %s\n",string1);

    char string3[SIZE];
    char string4[] = "Good Bye";

    copy2(string3,string4);
    printf("string3 = %s\n",string3);
}
void copy1(char *const s1, const char *const s2){
    //check the string has \0 in it, if yes then the printing stops
    for(size_t i = 0; (s1[i]=s2[i]) != '\0'; ++i){
        ;
    }
}
void copy2(char *s1,const char *s2){
    for(; (*s1 = *s2) != '\0';++s1 , ++s2){
        ;
    }
}
*/

// example ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Important notes

/*
#include <stdio.h>
int main(){
    {
        int array[5];

        array[2] =  5;

        // memory of first element ie. array[0]
        printf("    array: %zu\n",array); 
        printf("array +1 : %zu\n\n",array +1);

        printf("   &array: %zu\n",&array);
        // memory of the whole (array size * int)
        // which is 5 * 4 == 20; 
        printf("&array +1: %zu\n\n",&array+1);
    }

    {
        int matrix[3][5] = {
            {0,1,2,3,4,},
            {5,6,7,8,9},
            {10,11,12,13,14}
        };

        // memory of the first element of first row
        printf("         matrix[1]: %zu\n",matrix[1]);
        printf("    matrix[1] +1: %zu\n",matrix[1] +1);
        printf(" *(matrix[1] +1): %zu\n",*(matrix[1] +1));
        // memory of the entire first row
        printf("\n       &matrix[1]: %zu\n",&matrix[1]);
        printf("    &matrix[1] +1: %zu\n",&matrix[1] + 1);
        printf(" *(&matrix[1] +1): %zu\n",*(&matrix[1] +1));

        int *Ptr = (int*)(&matrix[1] + 1);

        printf(" \npointer: %zu\n", Ptr);
        printf("*pointer: %zu\n",*Ptr);
    }

}
*/
// 7.11 card shuffling and Dealing Simulation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Extremely fun 

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
void shuffle(unsigned int wDeck[][FACES]);  
                                        // const char *Ptr (const pointer to char)
                                        // mem can change data no change
void deal(unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[]);
int main(){

    unsigned int deck[SUITS][FACES] = {0};

    srand(time(NULL));

    shuffle(deck);

    const char *suit[SUITS] = 
        {"Hearts","Diamonds","clubs","Spades"};

    const char *face[FACES] = 
        {"Ace","Deuce","Three","Four",
        "Five","Six","Seven","Eight",
        "Nine","Ten","Jack","Queen","King"};

    deal(deck,face,suit);

    return 0;
}
void shuffle(unsigned int wDeck[][FACES]){
    // card is less than 52 , ++
    for(size_t card = 1; card <= CARDS; ++card){
        size_t row;
        size_t column;

        //randomly  generate number until there is 0 found in both
        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        }while(wDeck[row][column] != 0);

        //if 0 is found on both arr, put number into it
        wDeck[row][column] = card;
    }
}
void deal(unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[]){
    for(size_t card = 1;card <= CARDS; ++card){
        // loop row from wDeck
        for(size_t row = 0;row <SUITS; ++row){
            // loop col of wDeck for current row
            for(size_t column = 0;column<FACES; ++column){

                if(wDeck[row][column] == card){
                    printf("%5s of %-8s%c",wFace[column],wSuit[row]
                        // 52 / 26 has 2 left so \n if is 0 then \t
                    ,card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
*/

// 7.12 Pointers to Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

/*
#include <stdio.h>
#define SIZE 10

void bubble(int work[],size_t size, int (*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a, int b);

int main(){
    int a[SIZE] ={2,6,4,8,10,12,89,68,45,37};

    printf("%s","Enter 1 to sort in ascending order,\n "
            "Enter 2 to sort in descending order: ");

    int order;
    scanf("%d",&order);

    puts("\nData items in original order");

    for(size_t counter = 0;counter < SIZE; ++counter){
        printf("%5d",a[counter]);
    }

    if(order == 1){
        bubble(a,SIZE,ascending);
        puts("\nData tems in ascending order");
    }
    else{
        bubble(a,SIZE,descending);
        puts("\nData items in descending order");
    }

    for(size_t counter = 0;counter < SIZE;++counter){
        printf("%5d",a[counter]);
    }
    puts("\n");
}
                                    // function pointer that points to a and b
void bubble(int work[],size_t size, int (*compare)(int a,int b)){
    void swap(int *element1Ptr, int *element2Ptr);

    for(unsigned int pass=1; pass<size; ++pass){
        for(size_t count = 0; count < size-1; ++count){
            if((*compare)(work[count],work[count+1])){
                swap(&work[count],&work[count+1]);
            }
        }
    }
}
void swap(int *element1Ptr, int *element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
 }
int ascending(int a,int b){
    return b < a;
}
int descending(int a, int b){
    return b > a;
}
*/

// function pointer examples ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//  !!!!! Function pointers are function 
//  to INSTRUCTION not DATA

#include<stdio.h>
#include <stdbool.h>
double add(double x,double y){
    return x + y;
}
int subtract(int x,int y){
    return x - y;
}
int multiply(int x,int y){
    return x * y;
}
int divide(int x,int y){
    return x / y;
}
//fucntion that return pointer to a function
//(*select_operation()) is a function but is a pointer to another function
// it return a pointer to a function that accept 2 int arguement and return int value
int (*select_operation())(int,int){
    int option = 0;
    printf("select an operation\n");
    printf("1: subtract\n");
    printf("2: multiply\n");
    printf("3: divide\n");
    printf("enter: ");
    scanf("%d",&option);

    if(option == 1)
        return subtract;
    else if (option == 2) 
        return multiply;
    else if(option == 3)
        return divide;
    else 
        return NULL;
}
bool freeze_F(int temperature){
    if (temperature <= 0) 
        return true;
    else 
        return false;
}
bool freeze_C(int temperature){
    if (temperature <= 32) 
        return true;
    else 
        return false;
}
// fucntion accept a 
//  pointer to a function
// that accept int as argument and return BOOL
void is_freezing(bool(*freeze_check)(int)){
    int temperature = 0 ;
    printf("enter temperature: ");
    scanf("%d",&temperature);

    if(freeze_check(temperature))
        printf("Its freezing\n");
    else
        printf("its not freezing\n");
}
int main(){

// -------------------Pointer to a function-------------------------------------------------------------------------------
    // a variable pointer (*addPtr) that points to a 
    // function with two double varaible
    // and return a double value
    double (*add_pointer)(double,double) = &add; //usd add also can
    // double pointer variable that points to a function that recieve 2 double

    double a = 20;
    double b = 10;

    double result = add_pointer(a,b);
    printf("result is: %.2f\n",result);

// ----------------------Arrays of pointer to function-----------------------------------------------------------------------------

    // an array pointer that 
        // >> takes two int data 
        // >> that points to 3 function
    int (*Array_Ptr[])(int,int) = {subtract,multiply,divide};
    // array of pointer to function that accept 2 int arguement return interger

   int product = (*Array_Ptr[1])(3,15);

    printf("product: %d\n",product);
    
// ------------------Variable that is pointer to a function(accept 2 int, return 1 int)------------------------------------------------------------------------------------

    // a variable operation that point to a function that accept 2 int arguement 
    // return an int value
    int (*operation)(int,int) = select_operation();
    // interger pointer to a function that recieve 2 interger arguement and return interger
    // result of select_operation to *operation

    printf("answer: %d\n",operation(20,5));

// -----------------------------------------------------------------------------------------

    //
    printf("\nCelsius... \n\n");
    is_freezing(freeze_C);
    is_freezing(freeze_C); 
}