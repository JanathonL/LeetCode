94. Binary Tree Inorder Traversal
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
stack stk
   1
    \
     2
    /
    3
18 min 
1 wrong 
time: O(N)
space: O(h)
*/
// refined
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur||!stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
            
        }
        return res;
    }
};