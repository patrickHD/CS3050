#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input_error.h"
#define UINT_MAX 65535

int second;

int uniNum(int* numlist, int num)
{
   int size=sizeof(numlist) / sizeof(int);
   int i=0;
   for(i=0; i<=size; i++)
   {
       if(numlist[i]==num)
       {
           return 0;
       }
   }

   return 1;
}

int parse(char* cNum)
{
    char* tmp=malloc(sizeof(char));
    int i=0;
    while(cNum[i] != '\0')
    {
        if(isdigit(cNum[i])==0 || (isspace(cNum[i])==1) || cNum[i]==' ' || cNum[i]=='\0')
        {
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
        else
        {
            tmp=realloc(tmp, sizeof(tmp)+sizeof(char));
            tmp[i]=cNum[i];
        }
        i++;

    }
    tmp[i]='\0';
    int num=atoi(tmp);
    return num;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }


    FILE* listFile=fopen(argv[1], "r");
    if(listFile==NULL)
    {
        exit(FILE_FAILED_TO_OPEN);
    }

    int* numArr=malloc(sizeof(int));
    int i=0;
    char buffer[UINT_MAX];
    while(fgets(buffer, UINT_MAX, listFile))
    {
        buffer[strlen(buffer)-1]='\0';
        char* token=strtok(buffer, " \n\r\t");
        numArr=realloc(numArr, sizeof(numArr)+sizeof(int));
        numArr[i]=parse(token);
        i++;
    }

    int* numList=malloc(sizeof(int));
    int* numOccur=malloc(sizeof(int));

    for(i=0; i<sizeof(numArr)/sizeof(int); i++)
    {
        if(uniNum(numList, numArr[i])==1)
        {
            numList=realloc(numList, sizeof(numList)+sizeof(int));
            numOccur=realloc(numOccur, sizeof(numOccur)+sizeof(int));
            numList[sizeof(numList) / sizeof(int)] = numArr[i];
            numOccur[sizeof(numOccur) / sizeof(int)]++;
        }
        else if(uniNum(numList, numArr[i])==0)
        {

            for(i=0; i<=sizeof(numList) / sizeof(int); i++)
            {
                if(numList[i]==numArr[i])
                {
                    numOccur[i]++;
                }
            }
        }
    }

    int second;
    int k;
    for(k=1; k<sizeof(numArr)/sizeof(int); k++)
    {
        if(numOccur[k]>numOccur[k-1])
        {
            second=numArr[k-1];
        }
    }

    printf("%d\n", second);

    if(fclose(listFile)!=0)
    {
        exit(FILE_FAILED_TO_CLOSE);
    }
    return 777;
}
