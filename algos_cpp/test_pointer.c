#include <stdio.h>

struct Node {
   int data;
   struct Node *next;
};

int main()
{
    struct Node * head = NULL;  
    printf("address of head 1 :%x\n", head);
    printf("address of head 2 :%x\n", &head);
    
}
