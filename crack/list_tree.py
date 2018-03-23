class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def preorder(root):
    if root == None:
        return
    print root.data
    preorder(root.left)
    preorder(root.right)

def list_to_tree(arr, start, end):
    if (end < start):
        return

    mid = (start + end) //2
    node = Node(arr[mid])
    node.left = list_to_tree(arr, start, mid-1)
    node.right = list_to_tree(arr, mid+1 , end)
    return node

array = [1, 2, 3, 4, 5, 6, 7]
array = sorted(array)
root =  list_to_tree(array, 0, len(array)-1)
print "preorder traversal"
preorder(root)
