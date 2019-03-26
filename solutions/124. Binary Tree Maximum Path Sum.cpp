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
bug free
refined
beat: 96%
3min
time: O(N)
space: O(h)
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int max_len = INT_MIN;
        helper(root, max_len);
        return max_len;
    }
    int helper(TreeNode* root, int& max_len){
        if(!root){
            return 0;
        }
        int left = helper(root->left, max_len);
        int right = helper(root->right, max_len);
        int sum = left+right+root->val;
        max_len = max(max_len, sum);
        int res = max(left,right)+root->val;
        return res>0? res:0;
    }
};