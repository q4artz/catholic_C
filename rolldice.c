#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIDE 7   // there is 6 side to a dice, 1 more cus start from 0
int main(){
    int face,roll,total;
    int frequency[SIDE] = {0}; // Frequency has the size of 7 initalized to 0
    srand(time(NULL));   // seed thing 

    for(roll=1; roll <= 6000; roll++){ // execute until roll == 6000
        face = rand() % 6+1;     // face copy random value from 1 to 6
        ++frequency[face];    // frequency with the same face value ++
        total += face;
    }
    printf("Face \t\t Frequency\n");
    for(face = 1; face < SIDE; face++ ){  // write down face until it is same as 6
        printf("%d\t\t %d\n",face,frequency[face]);  // write face and frequency.
    }
    printf("total == %d",total);
    return 0;
}