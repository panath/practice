#include <vector>
#include <stddef.h>
#include <exception>
#include <cassert>

struct NotFoundException : std::exception {

};


struct Node {
   Node *left;
   Node *right;
   int key, val;

   Node(int key, int val): left(nullptr), right(nullptr), key(key), val(val) {}
   ~Node() {
        delete left;
        delete right;
   }

};


class BinarySearchTree {
    Node *root;
    static Node *findMin(Node *node, Node **parent = 0) {
        if (!node) return nullptr;
        while (node->left) {
            if (parent) *parent = node;
            node = node->left;
        }

    }

    static Node* findKey(Node *root, int key, Node** parent=0) {
        if (parent) *parent = nullptr;
        Node *curr = root;

        while (curr) {
            if (curr->key == key) {
                return curr;
            }
            else if (key < curr->key) {
                if (parent) *parent = curr;
                curr = curr->left;
            }
            else {
                if (parent) *parent = curr;
                curr = curr->right;

            }
        }

        return nullptr;
    }


public:



    int get(const int key) {
        Node *node = findKey(root, key);
        if (!node)
            throw NotFoundException();
    }


    return node->key;
};


void assertEquals(const std::vector<int> & expected, const std::vector actual) {
    if (expected != actual) {
         std::cout << "Expected : ";
         for (int num : expected) std::cout << num << " ";
         std::cout << std::endl;

         std::cout << "Actual : ";
         for (int num : actual) std::cout << num << " ";
         std::cout << std::endl;
    }
}

int main() {

}
