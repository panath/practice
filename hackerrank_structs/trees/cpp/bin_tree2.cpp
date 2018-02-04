#include <iostream>
#include <queue>
#include <climits>


using namespace std;


struct Node {
   Node *left;
   Node *right;
   int data;

   Node(int data):left(nullptr), right(nullptr), data(data) {}

   ~Node(){
      delete left;
      delete right;
   }
};

Node * CreateNewNode(int data) {
  Node * newNode = new Node(data);
  return newNode;
}

Node * InsertNode(Node *root, int data) {
    if (root == nullptr) {
       root = CreateNewNode(data);
    }
    else if (root->data > data) {
       root->left = InsertNode(root->left, data);
    }
    else {
       root->right = InsertNode(root->right, data);
    }
    return root;
}

void BreadFSearch(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> my_q;
    my_q.push(root);
    while (!my_q.empty()) {
        Node *current = my_q.front();
        cout << current->data << " ";
        if (current->left != nullptr)
            my_q.push(current->left);
        if (current->right != nullptr)
            my_q.push(current->right);
        my_q.pop();
    }

}

void PostOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " " ;
}

void PreOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " " ;
    PreOrder(root->left);
    PreOrder(root->right);
}

int height(Node *root) {
    if (root==nullptr)
        return -1;
    else return max(height(root->left), height(root->right)) + 1;
}

bool ISBSTUtil(Node *root, int minValue, int maxValue) {
    if (root == nullptr)
        return true;

    if (root->data < minValue || root->data > maxValue) 
     return false; 
 
  return
    ISBSTUtil(root->left, minValue, root->data-1) &&
    ISBSTUtil(root->right, root->data+1, maxValue);
}

bool IsBinarySearchTree(Node *root) {
    return ISBSTUtil(root, INT_MIN, INT_MAX); 
}


int main() {
  Node *root = nullptr;
  root = InsertNode(root, 4);
  root = InsertNode(root, 3);
  root = InsertNode(root, 5);
  root = InsertNode(root, 6);
  root = InsertNode(root, 1);
  root = InsertNode(root, 7);
  cout << "bsf " << endl;
  BreadFSearch(root);
  cout << endl;
  cout << "PreOrder " << endl;
  PreOrder(root);
  cout << endl;
  cout << "PostOrder " << endl;
  PostOrder(root);
  cout << endl;
  cout << "height " << endl;
  cout << height(root);
  cout << endl;
  cout << "Is Binary Search Tree " << endl;
  cout << (IsBinarySearchTree(root) ?"true":"false") << endl;
}
