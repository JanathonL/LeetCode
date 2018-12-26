145. Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* cur=root;
        TreeNode* last = NULL;
        while(cur!=NULL){
            s.push(cur);
            cur=cur->left;
        }
        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(cur->right==NULL||last==cur->right){
                res.push_back(cur->val);
                last = cur;
            }
            else{
                s.push(cur);
                cur=cur->right;
                while(cur){
                    s.push(cur);
                    cur=cur->left;
                }
                
            }
        }
        return res;
    }
};