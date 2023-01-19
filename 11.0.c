#include <stdlib.h>
#include <stdio.h>

int main(){
    /*
    not so diff from unix file sys
    r -read
    w -write
    a -add
    */
    FILE *FilePointer  = fopen("test.txt","r");
    fprintf(FilePointer,"hel");

    char PrintLine[50];
    fgets(PrintLine,50,FilePointer);
    printf("%s\n",PrintLine);

    fclose(FilePointer);
}