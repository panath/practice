class Node:
    """Class Node"""
    def __init__(self, data):
        """Constructor of a Node"""
        self.data = data
        self.left = None
        self.right = None
 
def swapEveryKLevelUtil(root, level, k):
    """Swap every K level Utility function"""
    if (root is None) or (root.left == None and root.right == None):
        return
    if (level+1)%k == 0:
        root.left, root.right = root.right, root.left
    swapEveryKLevelUtil(root.left, level+1, k)
    swapEveryKLevelUtil(root.right, level+1, k)

def swapEveryKLevel(root, k):
    """Swap Every K level"""
    swapEveryKLevelUtil(root, 1, k)
 
def inorder(root):
    """Inorder traversal""" 
    # Base Case
    if root is None:
        return
    inorder(root.left)
    print root.data
    inorder(root.right)
 
# Driver code
"""
          1
        /   \
       2     3
     /      /  \
    4      7    8
                 \
                  9 
"""
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.right.right = Node(8)
root.right.left = Node(7)
root.right.right.right = Node(9)
 
k = 2
print "Before swap node :"
inorder(root)
 
swapEveryKLevel(root, k)
 
print "\nAfter swap Node : "
inorder(root)
 
# This code is contributed by Nikhil Kumar Singh(nickzuc
