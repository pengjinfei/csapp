#include "cachelab.h"
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SLEN 81
#define TLEN 81

struct cache_line {
    int valid;
    unsigned long tag;
    int time_stamp;
};

static int b_mask;
static int s_mask;
static int b = 0;
static int s = 0;
static int e = 0;

static int get_b(unsigned long *addr) {
    unsigned long temp = *addr;
    temp = temp & b_mask;
    *addr = *addr >> b;
    return temp;
}


static int get_s(unsigned long *addr) {
    unsigned long temp = *addr;
    temp = temp & s_mask;
    *addr = *addr >> s;
    return temp;
}

int main(int argc, char *argv[]) {
    int ch;
    int vFlag = 0;
    char fileName[SLEN];
    while ((ch = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (ch) {
            case 'h':
                printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
                       "Options:\n"
                       "  -h         Print this help message.\n"
                       "  -v         Optional verbose flag.\n"
                       "  -s <num>   Number of set index bits.\n"
                       "  -E <num>   Number of lines per set.\n"
                       "  -b <num>   Number of block offset bits.\n"
                       "  -t <file>  Trace file.\n"
                       "\n"
                       "Examples:\n"
                       "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
                       "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace");
                exit(EXIT_SUCCESS);
            case 'v':
                vFlag = 1;
//                printf("vFlag is %d.\n", vFlag);
                break;
            case 's':
                s = atoi(optarg);
//                printf("s is %d.\n", s);
                break;
            case 'E':
                e = atoi(optarg);
//                printf("E is %d.\n", e);
                break;
            case 'b':
                b = atoi(optarg);
//                printf("b is %d.\n", b);
                break;
            case 't':
                strcpy(fileName, optarg);
//                printf("fileName is %s.\n", fileName);
                break;
            default:
                printf("Not a valid argument.\n");
                exit(EXIT_FAILURE);
        }

    }
    if (s <= 0) {
        printf("s is needed.");
        exit(EXIT_FAILURE);
    }
    s_mask = (1 << s) - 1;
    if (b <= 0) {
        printf("b is needed.");
        exit(EXIT_FAILURE);
    }
    b_mask = (1 << b) - 1;
    if (e <= 0) {
        printf("E is needed.");
        exit(EXIT_FAILURE);
    }
    int size = (1 << s) * e;
    struct cache_line *cache;
    cache = malloc(size * sizeof(struct cache_line));
    for (int j = 0; j < size; ++j) {
        cache[j].valid = 0;
        cache[j].tag = -1;
        cache[j].time_stamp = -1;
    }
    FILE *fp;
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Can't open file %s.\n", fileName);
        exit(EXIT_FAILURE);
    }
    char mode_str[2];
    unsigned long addr;
    int bytes;
    int index;
    unsigned long tag;
    int time_stamp = 0;

    int misses = 0;
    int hits = 0;
    int evictions = 0;
    while ((fscanf(fp, "%1s", mode_str) == 1)) {
        fscanf(fp, "%lx,%d", &addr, &bytes);
        if (mode_str[0] == 'I') {
            continue;
        }
        if (vFlag) {
            printf("%s %lx,%d", mode_str, addr, bytes);
        }
        get_b(&addr);
//        printf(" b=%d ", shift);
        index = get_s(&addr);
//        printf(" s=%d", index);
        index = index * e;
        tag = addr;
        time_stamp++;
        int found = 0;
        int found_empty = -1;
        int max_stamp = INT_MAX;
        int max_index = index;
        for (int i = 0; i < e; i++) {
            if (cache[index + i].valid == 0) {
                if (found_empty == -1) {
                    found_empty = index + i;
                }
                continue;
            }
//            printf(" cache[%d].valid=%d", index + i, cache[index + i].valid);
            if (cache[index + i].tag == tag) {
                if (vFlag) {
                    printf(" hit");
                }
                cache[index + i].time_stamp = time_stamp;
                hits++;
                found = 1;
                break;
            }
            if (found_empty == -1 && max_stamp > cache[index + i].time_stamp) {
                max_stamp = cache[index + i].time_stamp;
                max_index = index + i;
            }
        }
        if (!found) {
            misses++;
            if (vFlag) {
                printf(" miss");
            }
            if (found_empty == -1) {
                evictions++;
                if (vFlag) {
                    printf(" eviction");
                }
                cache[max_index].time_stamp = time_stamp;
                cache[max_index].tag = tag;
            } else {
                cache[found_empty].time_stamp = time_stamp;
                cache[found_empty].tag = tag;
                cache[found_empty].valid = 1;
            }
        }
        if (mode_str[0] == 'M') {
            hits++;
            if (vFlag) {
                printf(" hit");
            }
        }
        if (vFlag) {
            printf("\n");
        }
    }
    fclose(fp);
    printSummary(hits, misses, evictions);
    return 0;

}

