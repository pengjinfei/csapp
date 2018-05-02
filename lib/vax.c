//
// Created by 彭金飞 on 5/2/18.
//

int bis(int x,int m){
    return x | m;
}

int bic(int x,int m) {
    return x & (~m);
}

int bool_or(int x,int m){
    return bis(x, m);
}

int bool_xor(int x,int y){
    return bis(bic(x, y), bic(y, x));
}