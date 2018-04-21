// 222. Count Complete Tree Nodes
// （1） 直接O(n) 搜索，会超时
// （2） O(h^2) 先搜索左右两边最大高度，
// 如果相等，说明最后一层也是满的，return pow(2,h)-1; 
// else return 1+coutn(root->left)+countn(root->right);

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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int hl=0,hr=0;
        TreeNode* l=root;
        TreeNode* r=root;
        while(l){
            hl++;
            l=l->left;
        }
        while(r){
            hr++;
            r=r->right;
        }
        if(hr==hl) return pow(2,hr)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         queue<TreeNode*> q;
//         if(!root) return 0;
//         int cnt=0;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* t = q.front();
//             cnt++;
//             q.pop();
//             if(t->left) q.push(t->left);
//             if(t->right) q.push(t->right);
//         }
//         return cnt;
//     }
// };