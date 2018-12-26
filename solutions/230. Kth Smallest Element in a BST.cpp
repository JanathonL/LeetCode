230. Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        // if(!root) return 0;
        vector<int> result;
        preOrder(root,result);
        return result[k-1];
    }
    void preOrder(TreeNode* root, vector<int>& result){
        if(!root) return;
        preOrder(root->left,result);
        result.push_back(root->val);
        preOrder(root->right,result);
    }
};