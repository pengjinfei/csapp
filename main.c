#include <stdio.h>
#include "lib/lib.h"

int main() {
    test_show_bytes(12345);
    char *s = "abcdef";
    show_chars(s);
    printf("%x", bool_xor(123, 456));
    return 0;
}