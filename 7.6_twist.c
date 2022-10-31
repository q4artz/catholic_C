/*
->> func with const pointer and non const pointer
->> another func to swap
->> some for loop
*/
#include <stddef.h>
#include <stdio.h>
#define SIZE 5
void ArrSort(char *const arrPtr,const size_t size);
// void
int main(){
    char arr[SIZE] ={'a','c','d','e','b'};

    puts("The character before rearrange is : ");
    for(size_t i = 0; i < SIZE; i++){
        printf("%4c  ",arr[i]);
    }

    //got = then use & if no dont use
    ArrSort(arr,SIZE);

     puts("The character After rearrange is : ");
    for(size_t i = 0; i < SIZE; i++){
        printf("%4c  ",arr[i]);
    }

}
void ArrSort(char *const arrPtr,const size_t size){
    void swap(char *arr1,char *arr2);

    for(int pass = 0;pass < size -1; pass++){
        for(size_t j = 0; j <size -1; j++){
            if((int)arrPtr[j] > (int)arrPtr[j +1]){
                swap(&arrPtr[j], &arrPtr[j+1]);
            }
        }
    }
}
void swap(char *arr1,char *arr2){
    char hold = *arr1;
    *arr1 = *arr2;
    *arr2 = hold;
}