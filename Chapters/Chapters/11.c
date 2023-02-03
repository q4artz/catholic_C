// Chapter 11 File Processing
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
int main(){
    /*
    r   -read
    w   -write (overwriting)
    a   -add
    r+  - (open existing file) read and write (OW off)
    w+  - (create new file ) read and write (OW on)
    a+  - (open/create file) read and write (OW off (append new data))
    */
    FILE *FilePointer  = fopen("test.txt","r");
    fprintf(FilePointer,"hel");
    fputc('a',FilePointer);
    fputs("\nthis is the puts line\n",FilePointer);

    char PrintFile = fgetc(FilePointer);
    while (PrintFile != EOF){
        PrintFile = fgetc(FilePointer);
        printf("%c", PrintFile);

    };
    fclose(FilePointer);

    // look at my python file repository for more info
}