
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input_error.h"

void DFS(int);
int getsize(FILE* in);

int main(int argc, char** argv) {

    int i=0;
    while(argv[i]!=NULL)
    {
        printf("%s \n", argv[i]);
        i++;
    }

    if(argc<2)
    {
        printf("incorrect args\n");
        return(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }

    FILE* graphfile = fopen(argv[1], "r");

    if(graphfile==NULL)
    {
        printf("file open fail\n");
        return(FILE_FAILED_TO_OPEN);
    }
    int gsize=getsize(graphfile);

    //printf("%c\n", fgetc(graphfile));

    return (EXIT_SUCCESS);

}

int getsize(FILE* in){
    int size=0;
    char c;
    char sizec[255];

    while(fscanf(in, "%s", sizec) != EOF)
    {
        fscanf(in, "%s", sizec);
        printf("%s", sizec);
    }

    return size;
}
