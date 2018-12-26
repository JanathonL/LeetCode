314. Binary Tree Vertical Order Traversal
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
    /*
    一定要把整个架构想明白了再去写代码！！！！
    13 min
    3 wrongs
    time: O(N)
    space: O(N)
    */
    void level_order(TreeNode* root, unordered_map<int, vector<int>>& dict, int& min_level, int& max_level){
        if(root==NULL){
            return;
        }
        queue<pair<TreeNode*,int>> que;
        que.push({root, 0});
        while(!que.empty()){
            pair<TreeNode*,int> parent = que.front();
            que.pop();
            TreeNode* cur = parent.first;
            int level = parent.second;
            dict[parent.second].push_back(cur->val);
            min_level = min(min_level, level);
            max_level = max(max_level, level);
            if(cur->left != NULL){
                que.push({cur->left, level-1});
            }
            if(cur->right != NULL){
                que.push({cur->right, level+1});
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> dict;
        int min_level = INT_MAX;
        int max_level = INT_MIN;
        level_order(root, dict, min_level, max_level);
        vector<vector<int>> res;
        for(int i=min_level;i<=max_level;i++){
            res.push_back(dict[i]);
        }
        return res;
    }
};