// Algorithm: buildTree()
// 1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
// 2) Create a new tree node tNode with the data as picked element.
// 3) Find the picked element’s index in Inorder. Let the index be inIndex.
// 4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
// 5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
// 6) return tNode.
/* program to construct tree using inorder and preorder traversals */
#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node { 
    char data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value); 
struct node* newNode(char data); 
  
/* Recursive function to construct binary of size len from 
   Inorder traversal in[] and Preorder traversal pre[].  Initial values 
   of inStrt and inEnd should be 0 and len -1.  The function doesn't 
   do any error checking for cases where inorder and preorder 
   do not form a tree */
struct node* buildTree(vector<char> in, vector<char> pre, int inStrt, int inEnd) 
{ 
    static int preIndex = 0; 
  
    if (inStrt > inEnd) 
        return NULL; 
  	struct node* root = newNode(pre[preIndex]);
  	preIndex++;
  	if (inStrt == inEnd) 
        return tNode; 
  	
  	int inIndex = search(in, inStrt, inEnd, root->data);
  	root->left = buildTree(in, pre, inStrt, inIndex-1);
  	root->right = buildTree(in, pre, inIndex+1, inEnd);
    return root;
} 
  

Efficient Approach : 
// We can optimize the above solution 
// using hashing (unordered_map in C++ or HashMap in Java). 
// We store indexes of inorder traversal in a hash table. 
// So that search can be done O(1) time.

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end] 
   The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            return i; 
    } 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    printf("%c ", node->data); 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    struct node* root = buildTree(in, pre, 0, len - 1); 
  
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root); 
    getchar(); 
} 