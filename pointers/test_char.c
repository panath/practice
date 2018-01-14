#include <stdio.h>
#include <stdlib.h>

void set(char *buf)
{
    buf = malloc(4*sizeof(char));
    buf = "test";
}

void set2(char **buf)
{
    *buf = malloc(5*sizeof(char));
    // 1. don't assign the other string, copy it to the pointer, to avoid memory leaks, using string literal etc.
    // 2. you need to allocate a byte for the null terminator as well
    strcpy(*buf, "test");
}


int main() {
    char *str = NULL;
    //set2(&str);
    //puts(str);
    set(str);
    puts(str);
}
