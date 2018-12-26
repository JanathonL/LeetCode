// 95. Unique Binary Search Trees II
// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode* clone(TreeNode* tree){
        if(tree==NULL){
            return NULL;
        }
        TreeNode* root = new TreeNode(tree->val);
        root->left = clone(tree->left);
        root->right = clone(tree->right);
        return root;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        res.push_back(NULL);
        for(int i=1;i<=n;i++){
            vector<TreeNode *> tmp;
            for(int j=0;j<res.size();j++){
                TreeNode* newroot = new TreeNode(i);
                TreeNode* oldroot = res[j];
                TreeNode* target = clone(oldroot);
                newroot->left = target;
                tmp.push_back(newroot);
                if(oldroot==NULL) continue;
                TreeNode* cur = oldroot;
                while(cur->right!=NULL){
                    TreeNode* nonroot = new TreeNode(i);
                    TreeNode* tright = cur->right;
                    cur->right = nonroot;
                    nonroot->left = tright;
                    TreeNode* target = clone(oldroot);
                    tmp.push_back(target);
                    cur->right = tright;
                    cur = cur->right;
                }
                cur->right = new TreeNode(i);
                target = clone(oldroot);
                tmp.push_back(target);
                cur->right = NULL; 
            }
            res = tmp;
        }
        return res;
    }
    
    // vector<TreeNode*> generateTrees(int n) {
    //     if(n==0) return vector<TreeNode*>();
    //     return dfs(1,n);
    // }
//     vector<TreeNode*> dfs(int minv, int maxv){
//         vector<TreeNode*> res;
//         if(minv>maxv){
//             res.push_back(NULL);
//             return res;
//         }
//         for(int i=minv;i<=maxv;i++){
//             vector<TreeNode*> leftSub = dfs(minv, i-1);
//             vector<TreeNode*> rightSub = dfs(i+1, maxv);
//             for(TreeNode* left: leftSub){
//                 for(TreeNode* right: rightSub){
//                     TreeNode* root = new TreeNode(i);
//                     root->left = left;
//                     root->right = right;
//                     res.push_back(root);
//                 }
//             }
//         }
        
        
//         return res;
        
        
//     }
    
};