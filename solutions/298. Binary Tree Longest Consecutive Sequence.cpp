// 298. Binary Tree Longest Consecutive Sequence
// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// Example 1:

// Input:

//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5

// Output: 3

// Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
// Example 2:

// Input:

//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1

// Output: 2 

// Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        int res= 0;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int &res) {
        if(!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if(root->left && root->left->val == root->val+1) l++;
        else l=1;
        if(root->right && root->right->val == root->val+1) r++;
        else r=1;
        res = max(res, max(l,r));
        return max(l,r);
    }
};