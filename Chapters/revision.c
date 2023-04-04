#include <stdio.h>
// Chapter 1 Structures ---------------------------------------------------

/* Normal Struct Declearation */
struct StructName{
    char character;     //(IN & OUT) %c 
    char string[10];    //(IN) %s or %[^\n]  
                        //(OUT) %s 
    int interger;       //(IN & OUT) %d
    double Double;      //(IN & OUT) %lf
    float Floating;     //(IN & OUT) %lf
}Structure1,Structure2;

void NormalStruct(){
    // have to put struct at the beggining

    struct StructName Structure1;
}

/* Typedef Struct Declearation */
typedef struct{
    int hi;
}StructureName;

/* Using Struct inside struct */

typedef struct{
    int day;
    int month;
    int year;
}date;

typedef struct{
    // NO INTIALIZATION IN STRUCTURE !!!!
    char name[10];
    date birthday;
    /* Inside birthday is 
            birthday.date
            birthday.month
            birthday.year
    */
}Student;

void DeclearAndCallStruct(){
    Student John = {
       .name="Johnny",
       .birthday.day = 21,
       .birthday.month= 12,
       .birthday.year = 1984
       // No need to put semi colon at the end
    }; 
    // !!!!! BUT after struct declear then need !!!!

    // call struct
    printf("John name is %s\n"
        "John Brithday is %d day , %d month  %d year"
        ,John.name,John.birthday.day,John.birthday.month,John.birthday.year);
}

/* struct Array */

struct StructAnotherName{
    int hi;
};

void StructArray(){
    struct StructAnotherName anotherstruct[50];

    anotherstruct = {
        [0].{anotherstruct.hi=1},
        [1].{anotherstruct.hi=2},
        [2].{anotherstruct.hi=3}};
}

strcmp() // compare string
strcpy() // copy string



// Chapter 2 File ---------------------------------------------------------------------------

/*
    // Declear file
    FILE *filePTR = fopen("file.txt","w / r / wb / rb");

    // close file 
    fclose(filePTR)

    //Print from text file
    while(fread(filePTR,"%d",&x) != EOF){
        printf("%d",x);
    };

    //write to text file
    fprintf(filePTR,"%d",&x);

*/

/*
    // print from binary file
    while(fread(&x,sizeof(int),1,filePTR) != 0){
        printf("%d",x);
    };

    // write to binary file
    fwrite(&x,sizeof(int),1,filePTR);
*/