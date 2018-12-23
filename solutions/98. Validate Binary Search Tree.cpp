98. Validate Binary Search Tree
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
7 min
3 wrong
time: O(N)
space: O(H)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        if(!root) return true;
        TreeNode* cur = root;
        int prev = INT_MIN;
        bool has_prev = false;
        while(cur||!stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if(has_prev && cur->val<=prev){
                    return false;
                }
                prev = cur->val;
                has_prev = true;
                cur = cur->right;
            }
        }
        return true;
    }
};