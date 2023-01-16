#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	
	float numbers[10] = {0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};

	float *nPtr;

// 7.3 E;
	puts("My asnwer: ");
	for(int i=0;i<10;i++){
		nPtr = &numbers[i];
		printf("%.1f\n",*nPtr);
	}

	puts("\n\"Real\" Answer : ");
	nPtr = numbers;
	for(size_t i=0; i<10; ++i){
		printf("%.1f\n",*(nPtr+i));
	}

// 7.3 F

	puts("\nMy answer");
	for(size_t i=0;i<10;i++){
		printf("%.1f\n",numbers[i]);
	}

	puts("\n\"Real\" Answer : ");
	for (size_t i =0; i<10; ++i)
		printf("%.1f\n",*(numbers + i));

// 7.3  G

	puts("My answer ");
	for(int i=0; i<10;i++){
		printf("%.1f\n",nPtr[i]);
	}

	puts("\n\"Real\" Answer : ");
	for(size_t i=0;i<10;i++)
		printf("%.1f\n",nPtr[i]);
	

// 7.3 H
	
	puts("\nMy Answer");
	// numbers[4];
	{
	*nPtr = numbers[4];
	printf("%.1f\n",*nPtr);
	}
	{
	nPtr = &numbers[4];
	printf("%.1f\n",*nPtr);
	}

	puts("\nReal Answer");
	{
	//numbers[4];
	//*(numbers + 4);
	// nPtr[4];
	// *(nPtr +4)
	};
}
