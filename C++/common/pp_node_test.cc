#include <stdio.h>
/* 
    1. prefix++与*的运算优先级相同，运算优先级相同的情况下，从右向左
    2. postfix++的运算优先级高于*，使用时从左向右
*/

int main() {
    int array[] = {10, 20, 30, 40, 50, 60};
    int *p = array;
    int a = *p; // 10, p =
    int b = *++p; // 20，p->
    int c = *p++; // 20, p-> 
    int d = ++*p; // 31, p =
    int e = *p; // 31, p =

    printf("a: %d, b: %d, c: %d, d: %d, e: %d\n", a, b, c, d, e);
    return 0;
}