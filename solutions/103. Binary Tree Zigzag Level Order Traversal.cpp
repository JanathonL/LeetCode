103. Binary Tree Zigzag Level Order Traversal
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
3 wrongs
8 min
time: O(n)
space: O(n)
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        // check empty
        if(!root) return res;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> temp(size, 0);
            int index;
            if(level%2==0){
                index = 0;
            } else {
                index = size-1;
            }
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                temp[index] = cur->val;
                if(level%2==0){
                    index++;
                } else {
                    index--;
                }
                if(cur->left){
                    que.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                }
            }
            res.push_back(temp);
            level++;
        }
        return res;
    }
};