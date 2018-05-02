//
// Created by 彭金飞 on 5/2/18.
//
#include <stdio.h>
#include <memory.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_chars(char *s){
    show_bytes((byte_pointer) s, strlen(s));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

