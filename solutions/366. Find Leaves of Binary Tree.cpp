366. Find Leaves of Binary Tree
// refined
// beat 63%
// time: O(N)
// space: O(H)

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        solver(root, res);
        return res;
    }
    /*
           1
         / \
        2   3
       / \     
      4   5     
    */
    int solver(TreeNode* root, vector<vector<int>>& res){
        if(!root) return -1;
        int lh =solver(root->left, res);  // lh = 
        int rh =solver(root->right, res);  // rh = 
        int rooth = max(lh,rh) + 1;      // rooth = 
        if(rooth==res.size()) {         // res.size() = 2   
            res.push_back(vector<int>());
        }
        res[rooth].push_back(root->val);
        return rooth;
    }
};