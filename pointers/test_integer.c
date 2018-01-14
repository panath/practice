#include <stdio.h>


int main() {
    int b = 4;
    int * a = &b;
    printf("%d\n", a);
    printf("%d\n", *a);
}
