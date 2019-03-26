114. Flatten Binary Tree to Linked List
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
do not know the reason
can not solve it
forget to set root-left = NULL
20 min
Time: O(NlogN)
space: O(h)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) {
            // cout<<"test"<<endl;
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right){
            root = root->right;
        }
        // cout<<left->val<<endl;
        root->right = right;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// refined
// time: O(NlogN)   ???
// space: O(H)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left&&root->right){
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* cur = root->right;
            while(cur->right){
                cur = cur->right;
            }
            cur->right = right;
        } else if(root->left){
            root->right = root->left;
            root->left = NULL;
        }
    }
};