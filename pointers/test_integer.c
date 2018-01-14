#include <stdio.h>

void func(int *new_integer) {
    new_integer = (int*)malloc(sizeof(int));
   *new_integer = 3;
}


int main() {
    int b = 4;
    int *a;//= &b;
    func(a);
    //printf("%x\n", a);
    printf("%d\n", *a);
}
