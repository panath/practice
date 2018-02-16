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

Node *findMin(Node *root) {
     if (root == nullptr || root->left == nullptr)
         return root;
     else 
         return findMin(root->left);
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

Node *find(Node *root, int data) {
    if (root == nullptr)
        return nullptr;
    if (root->data == data)
        return root;
    else if (root->data > data)
        return find(root->left, data);
    else
        return find(root->right, data);
}

Node *GetSuccessor(Node *root, int data) {
    Node * current = find(root, data);
    if (current == nullptr)
        return nullptr;
    if (current->right != nullptr)
        return findMin(current->right);
    else {
        Node * successor = nullptr;
        Node * ancestor = root;
        while (ancestor != current ) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
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

struct Node* Delete(Node *root, int data) {
    if (root == nullptr)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else {
        if ((root->left == nullptr) && (root->right == nullptr)) {
            delete root;
            root = nullptr;
            return root;
        }
        else if (root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (root->right == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, data);
        }
    }
    return root;  
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
  cout << "findMin " << endl;
  cout << findMin(root)->data << endl;
}
