113. Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        valid(root,sum,tmp);
        return result;
    }
    void valid(TreeNode* root, int sum, vector<int>& tmp){
        if(!root) {
            return;
        }
        tmp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==root->val){
                // tmp.push_back(root->val);
                result.push_back(tmp);
                tmp.pop_back();
                return ;
            }
            else{
                tmp.pop_back();
                return ;
            }
        }
        valid(root->left,sum-root->val,tmp); 
        valid(root->right,sum-root->val,tmp);
        tmp.pop_back();
        
    }
private:
    vector<int> tmp;
    vector<vector<int>> result;
};