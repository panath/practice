// Recursive C++ program for level order traversal of Binary Tree
#include <iostream>

using namespace std;

 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct TreeNode{
    TreeNode * left; 
    TreeNode *right;
    int data;
    TreeNode(int value):left(nullptr), right(nullptr), data(value) {}
    ~TreeNode() {}
};

 
/* Function protoypes */
void printGivenLevel(TreeNode* root, int level);
int height(TreeNode* node);
TreeNode* newNode(int data);
 
/* Function to print level order traversal a tree*/
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
/* Print nodes at a given level */
void printGivenLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(TreeNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


void deleteTree(TreeNode *node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    cout << "Deleting node " << node->data << endl;
    delete node;
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode* newNode(int data)
{
    TreeNode* node = new TreeNode(data);
 
    return(node);
}
 
/* Driver program to test above functions*/
int main()
{
    struct TreeNode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    deleteTree(root);
 
    return 0;
}
