// 156. Binary Tree Upside Down
// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

// Example:

// Input: [1,2,3,4,5]

//     1
//    / \
//   2   3
//  / \
// 4   5

// Output: return the root of the binary tree [4,5,2,#,#,3,1]

//    4
//   / \
//  5   2
//     / \
//    3   1  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        helper(root);
        return head?head:root;
    }
    TreeNode* helper(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* l = helper(root->left);
        TreeNode* r = root->right;
        if(l){
            if(!head) {
                head = l;
            }
            l->left = r;
            l->right = root; 
            root->left = NULL;
            root->right = NULL;
        }
        return root;
        
    }
};