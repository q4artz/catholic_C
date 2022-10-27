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

// PASS BY VALUE FUNCTION POINTER
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

// PASS BY VALUE ARRAY FUCNTION POINTER
#include <stdio.h>
int arr(int i);
int main(){
    int result;
    int (*Ptr)[5];
    result = (*Ptr[5]);
    for (int j = 0 ;j <= 5; j++){
    printf("array is now %d\n",result);
    }
}
int arr(int i){
    for (i=0;i<=5;i++){
        return i;
    }
}

// 7.5 Using the const Qualifier with pointers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

