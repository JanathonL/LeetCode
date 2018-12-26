199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        queue<TreeNode*> current,next;
        current.push(root);
        while(!current.empty()){
            int tmp = INT_MIN;
            while(!current.empty()){
                TreeNode* t = current.front();
                current.pop();
                tmp = t->val;
                if(t->left!=NULL) next.push(t->left);
                if(t->right!=NULL) next.push(t->right);
            }
            swap(next,current);
            result.push_back(tmp);
        }
        return result;
    }
};