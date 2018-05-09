#include <stdio.h>
#include <inttypes.h>
#include "lib/lib.h"

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

    return 0;
}



