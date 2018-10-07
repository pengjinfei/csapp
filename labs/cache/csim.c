#include "cachelab.h"
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81

typedef struct
{
    int valid;
    int tag;
    int time_stamp;
} cache_line;

int main(int argc, char * argv[])
{
    int ch;
    int fFlag = 0;
    int vFlag = 0;
    int s = 0;
    int e = 0;
    int b = 0;
    char fileName[SLEN];
    while((ch=getopt(argc,argv,"hvs:E:b:t:"))!=-1) {
        switch (ch) {
            case 'h':
                fFlag = 1;
                printf("fFlag is %d.\n",fFlag);
                break;
            case 'v':
                vFlag = 1;
                printf("vFlag is %d.\n",vFlag);
                break;
            case 's':
                s = atoi(optarg);
                printf("s is %d.\n", s);
                break;
            case 'E':
                e = atoi(optarg);
                printf("E is %d.\n", e);
                break;
            case 'b':
                b = atoi(optarg);
                printf("b is %d.\n", b);
                break;
            case 't':
                strcpy(fileName,optarg);
                printf("fileName is %s.\n",fileName);
                break;
            default:
                break;
        }
    }
//    printSummary(0, 0, 0);
    return 0;
}
