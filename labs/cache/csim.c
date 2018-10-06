#include "cachelab.h"
#include <getopt.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int ch;
    while((ch=getopt(argc,argv,"hvs:E:b:t:"))!=-1) {
        switch (ch) {
            case 'h':
                break;
        }
    }
    printSummary(0, 0, 0);
    return 0;
}
