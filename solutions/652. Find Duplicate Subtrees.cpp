652. Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> ans;
        helper(m, root, ans);
        return ans;
    }
    string helper(unordered_map<string, int>& m, TreeNode* root, vector<TreeNode*>& ans){
        if(!root) return "";
        string res_str = to_string(root->val) + '$' + helper(m,root->left,ans)+ '$'+helper(m,root->right,ans) + '$';
        // cout<<res_str<<endl;
        m[res_str]++;
        if(m[res_str]==2){
            ans.push_back(root);
        }
        return res_str;
    }
    
};