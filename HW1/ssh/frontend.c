#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"
#define UINT_MAX 200

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("args error\n");
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }

    FILE* listFile=fopen(argv[1], "r");
    if(listFile==NULL)
    {
        printf("file open error\n");
        exit(FILE_FAILED_TO_OPEN);
    }

    char buffer[UINT_MAX];
    while(fgets(buffer, UINT_MAX, listFile))
    {
        buffer[strlen(buffer)-1]='\0';
        char* token=strtok(buffer, " \n\r\t");
        printf("%s\n", token);
    }

    return 69;
}

