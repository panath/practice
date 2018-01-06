#include <iostream>

using namespace std;


/*
Node of a BST
*/
struct Node {
   int data;
   Node *left;
   Node *right;

   Node(int d) {
       data = d;
       left = nullptr;
       right = nullptr;
   }

};

/*
 BST
*/
class BST {

private:
   Node *root;
   int size;

public:
   BST() {
       root = nullptr;
       size = 0;
   }
   ~BST() {
      clear(root);
   }

   void clear(Node *n) {
       if (n != nullptr) {
           clear(n->left);
           clear(n->right);
           delete n;
       }
   }
   
   bool contains(int d) {
       Node *n = root;
       bool found = false;

       while (n != nullptr && !found) {
           if (n->data == d) {
               found = true;
           }
           else if (d < n->data) {
              n = n->left;
           }
           else {
              n = n->right;
           }
       }
       return found;
   }

   void insert(int d) {
       if (!root) {
           root = new Node(d);
           size++;
           return;
       }
       Node *n = root;
       while (n != nullptr)
       {
           if (d < n->data) {
               if (n->left == nullptr) {
                   n->left = new Node(d);
                   size++;
                   break;
               }
               else {
                  n = n->left;
               }
           }
           else {
               if (n->right == nullptr) {
                   n->right = new Node(d);
                   size++;
                   break;
               }
               else {
                  n = n->right;
               }
           }
       }
   }
};

int main() {
  BST b;
  b.insert(90);
  b.insert(50);
  b.insert(190);
  b.insert(20);
  b.insert(80);
  b.insert(70);
  b.insert(62);
  b.insert(68);

  cout << boolalpha << "contains 60 " << b.contains(60) << endl;
}
