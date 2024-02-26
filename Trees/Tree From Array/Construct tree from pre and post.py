class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to perform inorder traversal on a given binary tree
def inorder(root):
 
    if root is None:
        return
 
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)
 
def find(data, arr):
    for i in range(len(arr)):
        if(arr[i] == data):
            return i
    return -1

def buildBinaryTree(pre, post):
    root = Node(pre[0])

    if len(pre)==1:
        return root
    pre = pre[1:]
    post = post[:-1]
    index = find(pre[0], post)

    root.left = buildBinaryTree(pre[:index+1], post[:index+1])
    root.right = buildBinaryTree(pre[index+1:], post[index+1:])
    return root
if __name__ == '__main__':
 
    preorder = [1, 2, 4, 5, 3, 6, 8, 9, 7]
    postorder = [4, 5, 2, 8, 9, 6, 7, 3, 1]
 
    root = buildBinaryTree(preorder, postorder)
 
    print('Inorder traversal is ', end='')
    inorder(root)
 