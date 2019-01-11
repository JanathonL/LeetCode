102. Binary Tree Level Order Traversal

// recursive 
// time: O(N)
// space: O(H)
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        treeLevel(root,1,result);
        return result;
    }
    void treeLevel(TreeNode* root, int level, vector<vector<int>>& result){
        if(!root) return;
        if(level>result.size()){
            result.push_back(vector<int> ());
        }
        result[level-1].push_back(root->val);
        treeLevel(root->left,level+1,result);
        treeLevel(root->right,level+1,result);
    }
};

// iterative
// time: O(N)
// space: O(H)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int sz = que.size();
            vector<int> tmp;
            for(int i=0;i<sz;i++){
                TreeNode* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};