#include <stdio.h>
#include <inttypes.h>
#include "lib/lib.h"
#include "lib/bits.h"

int equals(int x,int y){
    return !(x ^ y);
}

int main() {
    test_show_bytes(12345);
    char *s = "abcdef";
    show_chars(s);
    printf("%x\n", bool_xor(123, 456));

//    2.1.8
    printf("equals=%d\n",equals(1, 2));
    printf("equals=%d\n",equals(2, 2));

//    2.1.9
    int32_t x = 123;
    uint64_t y = 234;
    printf("x = %" PRId32 ",y = %" PRIu64 "\n",x,y);
    short a = 12345;
    short ma = -a;
    unsigned short ua = 53191;
    show_short(a);
    show_short(ma);
    show_short(ua);

    printf(" %d bitAnd %d = %d\n", 1, 2, bitAnd(1, 2));
    printf(" %d bitAnd %d = %d\n", 1, 3, bitAnd(1, 3));
    printf(" %d bitAnd %d = %d\n", 1, 4, bitAnd(1, 4));

    printf("getByte(0x%x,%d) = 0x%x\n", 0x12345678,1,getByte(0x12345678,0));
    printf("getByte(0x%x,%d) = 0x%x\n", 0x12345678,1,getByte(0x12345678,1));
    printf("getByte(0x%x,%d) = 0x%x\n", 0x12345678,1,getByte(0x12345678,2));
    printf("getByte(0x%x,%d) = 0x%x\n", 0x12345678,1,getByte(0x12345678,3));

    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,0,logicalShift(0x87654321,0));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,1,logicalShift(0x87654321,1));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,2,logicalShift(0x87654321,2));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,3,logicalShift(0x87654321,3));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,4,logicalShift(0x87654321,4));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,8,logicalShift(0x87654321,8));
    printf("logicalShift(0x%08x,%d) = 0x%08x\n", 0x87654321,8,logicalShift(0x87654321,31));
    return 0;
}



