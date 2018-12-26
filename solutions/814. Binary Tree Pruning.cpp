814. Binary Tree Pruning
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) return root;
        root = dfs(root);
        pre(root);
        return root;
    }
    TreeNode* dfs(TreeNode* root){
        if(root==nullptr) return nullptr;
        if(root->right== nullptr && root->left == nullptr){
            return root->val==1? root:nullptr;
        }
        if(root->left) root->left = dfs(root->left);
        if(root->right) root->right = dfs(root->right);
        if(root->val==0){
            if(root->left && (root->left->val==1||root->left->val==11) || root->right && (root->right->val==1||root->right->val==11)){
                root->val=11;
            }
            else{
                return nullptr;
            }
        }
        return root;
    }
    void pre(TreeNode* root){
        if(!root) return ;
        if(root->val == 11) root->val = 0;
        if(root->left) pre(root->left);
        if(root->right) pre(root->right);
    }
};