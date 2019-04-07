230. Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        // if(!root) return 0;
        vector<int> result;
        preOrder(root,result);
        return result[k-1];
    }
    void preOrder(TreeNode* root, vector<int>& result){
        if(!root) return;
        preOrder(root->left,result);
        result.push_back(root->val);
        preOrder(root->right,result);
    }
};

// refined beat 81%
// time: O(N)
// space: O(H)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        inOrder(root, k, res);
        return res;
    }
    void inOrder(TreeNode* root, int& k, int& res){
        if(root==NULL || k==0){
            return;
        }
        inOrder(root->left, k, res);
        if(k==1){
            res = root->val;
        }
        k--;
        inOrder(root->right, k, res);
    }
};

// stack
// refined 
// time: O(N)
// space: O(H)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        int cnt = 0;
        while(!stk.empty() || cur){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                cnt++;
                if(cnt == k){
                    return cur->val;
                }
                cur = cur->right;
            }
        }
        return cur->val;
    }
};

