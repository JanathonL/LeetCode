102. Binary Tree Level Order Traversal
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
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         TreeNode *tmp = new TreeNode(INT_MIN);
//         q.push(tmp);
//         vector<int> res;
//         while(!q.empty()){
            
//             TreeNode* t = q.front();
//             q.pop();
            
//             if(t->left!=NULL){
//                 q.push(t->left);
//             }
//             if(t->right!=NULL){
//                 q.push(t->right);
//             }
//             if(t->val==INT_MIN){
                
//                 vector<int> res_tmp;
//                 res_tmp.swap(res);
//                 ans.push_back(res_tmp);
                
//                 if(!q.empty())
//                     q.push(t);
//             }
//             else{
//                 res.push_back(t->val);
//             }
//         }
//         return ans;
//     }
// };