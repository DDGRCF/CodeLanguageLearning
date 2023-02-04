#include <iostream>
#include <stdio.h>


struct Test0 {
    char m1;
    double m2;
    int m3;
};


#pragma pack(push)
#pragma pack(4)

struct Test1 {
    char m1;
    double m2;
    int m3;
};

#pragma pack(pop)

#pragma pack(push)
#pragma pack(8)

struct Test2 {
    char m1;
    double m2;
    int m3;
};

#pragma pack(pop)

int main() {
    Test0 t0;
    Test1 t1;
    Test2 t2;
    printf("t0: %ld, t1: %ld, t2: %ld\n", sizeof(t0), sizeof(t1), sizeof(t2));
}