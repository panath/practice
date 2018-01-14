class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None

def height(root):
    if (root == None):
        return -1
    else:
        return 1 + max(height(root.left), height(root.right))

node = Node(3)
node.left = Node(2)
node.left.left = Node(1)
node.right = Node(6)
node.right.right = Node(7)
node.right.right = Node(7)
node.right.right.right = Node(9)
assert (height(node) == 3)
