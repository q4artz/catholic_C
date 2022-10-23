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

//~~~~~~~~~~~~~~~~~~~~~~~~  %p is printing for a pointer address ~~~~~~~~~~~~~~~~~~~~~~//
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