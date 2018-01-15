class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None

def max_height(root):
    if (root == None):
        return -1
    else:
        return 1 + max(max_height(root.left), max_height(root.right))

def min_height(root):
    if (root == None):
        return -1
    else:
        return 1 + min(min_height(root.left), min_height(root.right))

def is_balanced(root):
    return (max_height(root) - min_height(root) <= 1)

node = Node(3)
node.left = Node(2)
node.left.left = Node(1)
node.right = Node(6)
node.right.right = Node(7)
node.right.right = Node(7)
node.right.right.right = Node(9)
assert is_balanced(node)
