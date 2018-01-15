class Node:

   def __init__(self, data):
       self.data = data
       self.left = None
       self.right = None

def binary_creation(my_array, start, end):
   if start > end:
       return None
   else:
       mid = (start + end)//2
       node = Node(my_array[mid])
       node.left = binary_creation(array, start, mid-1)
       node.right = binary_creation(array, mid+1, end)
       return node 

def convert_array_to_tree(my_array):
    sorted_array = sorted(my_array)
    create_tree = binary_creation(my_array, 0, len(my_array)-1
    return create_tree

test_array = [1, 2, 4, 9, 5]
root = convert_array_to_tree(test_array)
