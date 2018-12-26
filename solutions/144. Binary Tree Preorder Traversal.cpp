144. Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if(tmp->right!=NULL) s.push(tmp->right);
            if(tmp->left!=NULL) s.push(tmp->left);
        }
        return res;
        
    }
};