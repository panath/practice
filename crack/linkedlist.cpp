#include <vector>
#include <stddef.h>
#include <exception>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node(int data):data(data),next(nullptr){}
    ~Node(){}
    
};


void print(struct Node * head) {

    struct Node * node = head;

    cout << "head" ;
    while (head != nullptr)
    {
        cout << "->" << head->data ;
        head = head->next;
    }

    cout << "->nullptr"  << endl;

}

int main() {

   Node *first = new Node(13);
   first->next = new Node(15);
   print(first);
   std::unordered_map<std::string, std::string> u;

   // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

}	
