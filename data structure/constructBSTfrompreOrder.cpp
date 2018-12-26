/* A O(n) program for construction of BST from preorder traversal */
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <vector>
using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
// A utility function to create a node 
struct node* newNode (int data) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// A recursive function to construct BST from pre[]. preIndex is used 
// to keep track of index in pre[]. 
struct node* constructTreeUtil( vector<int> pre, int& preIndex, int key, 
                                int min, int max) 
{ 
    if (preIndex>pre.size())
    {
        return NULL;
    }
    struct node* root = NULL;
    if (key>min && key<max)
    {
        root = newNode(pre[preIndex]);
        preIndex++;
        root->left = constructTreeUtil(pre, preIndex, pre[preIndex], min, root->data);
        root->right = constructTreeUtil(pre, preIndex, pre[preIndex], root->data, max);
    }
   
    return root; 
} 
  
// The main function to construct BST from given preorder traversal. 
// This function mainly uses constructTreeUtil() 
struct node *constructTree (vector<int> pre) 
{ 
    int index=0;
    return constructTreeUtil ( pre, index, pre[0], INT_MIN, INT_MAX); 
} 
  
// A utility function to print inorder traversal of a Binary Tree 
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
} 
  
// Driver program to test above functions 
int main () 
{ 
    int arr[] = {10, 5, 1, 7, 40, 50};
    vector<int> pre(arr,arr+6); 
    int size = pre.size(); 
  
    struct node *root = constructTree(pre); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    printInorder(root); 
  
    return 0; 
} 