#include <stdio.h>
#include <stdlib.h>


struct person
{
   int age;
   float weight;
};

typedef struct person test_struct;

void func(struct person *x); 


int main() {
    test_struct *personPtr= NULL;
    personPtr = (test_struct *)malloc(sizeof(test_struct));
    func(personPtr);
    printf("%d\n", personPtr->age);
    free(personPtr);
}


void func(struct person *x) { 
    x->age = 12;
}
