// 101. Symmetric Tree
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        else{
            return dfs(root->left, root->right);
        }
    }
    bool dfs(TreeNode* l, TreeNode* r){
        if(l==NULL&&r==NULL){
            return true;
        }
        else if(l&&r&&l->val == r->val){
            return dfs(l->left,r->right) && dfs(l->right, r->left);
        }
        else{
            return false;
        }
    }
};