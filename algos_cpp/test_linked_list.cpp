#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedList {

private:
    Node *root;
    int size;

public:
    LinkedList() {
        size = 0;
        root = nullptr;
    }
 
    ~LinkedList() {
        while (root != nullptr)
        {
            Node* next = root->next;
            delete root;
            root = next;
        }

    }

    void insert(unsigned int index, int d) {
        if (index == 0)
        {
            Node *n = new Node(d);
            n->next = root;
            root = n;
        }
        else {
            Node *n = root;
            for (int i=1; i < index && n->next != nullptr; i++) {
                n = n->next;
            }
            n->next = new Node(d);
        } 
        size++;
    }

    void remove(unsigned int index) {
        Node *p = root;
        if (index == 0) {
            Node *n = root->next;
            delete root;
            root = n;
            size--;
            return;   
        }

        for (int i=1; i < index && p->next != nullptr; i++)
        {
            p = p->next; 
        }
        if (p->next !
       
    }
};
