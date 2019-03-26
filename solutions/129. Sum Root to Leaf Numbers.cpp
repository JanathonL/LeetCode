129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        sum = 0;
        dfs(root,0);
        return sum;
    }
    void dfs(TreeNode* root, int cur){
        if(!root) return;
        cur = cur*10 + root->val;
        if(root&&root->left==nullptr&&root->right==nullptr){
            sum+=cur;
            cur/=10;
            return;
        }
        dfs(root->right,cur);
        dfs(root->left,cur);
        cur/=10;
        
    }
private:
    int sum;
};


// refined
// beat 100%
// time: O(N)
// space: O(H)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
    void dfs(TreeNode* root, int& sum, int cur){
        if(root==NULL){
            return;
        }
        cur = cur*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum += cur;
            return;
        }
        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
        
    }
};