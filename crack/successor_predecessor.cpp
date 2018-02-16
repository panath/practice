#include <iostream>
using namespace std;


struct Node {
    Node *left;
    Node *right;
    int key;
    Node(int key): left(nullptr), right(nullptr), key(key) {}
    ~Node() {
        delete left;
        delete right;
    }
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
    if (root == nullptr) return;
    
    if (root->key == key) {
        if (root->left != nullptr) {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

    }

    if (root->key > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root->left, pre, suc, key);
    }
}


Node *insert(Node *node, int key) {

    if (node == nullptr) return  new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else 
        node->right = insert(node->right, key);
    return node;
}



int main() {
    Node *root = nullptr;
    Node *pre = nullptr, *suc = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    findPreSuc(root, pre, suc, 65);
    if (pre != nullptr)
        cout << pre->key << endl;
    else 
        cout << suc->key << endl;

}
