// 那道 complete binary tree 求node count
// 222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int hl = getHeight(root->left, true);
        int hr = getHeight(root->right, false);
        if(hl==hr) return pow(2,hl+1) - 1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
    int getHeight(TreeNode* root, bool isLeft){
        if(root == NULL) return 0;
        if(isLeft) return getHeight(root->left,isLeft)+1;
        else return getHeight(root->right,isLeft)+1;
    }
};