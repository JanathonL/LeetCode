// 337. House Robber III
// 树形动规。设状态 f(root) 表示抢劫root为根节点的二叉树，root可抢也可能不抢，能得到的最大金钱，
// g(root)表示抢劫root为根节点的二叉树，但不抢root，能得到的最大金钱，则状态转移方程为
// f(root) = max{f(root.left) + f(root.right),  g(root.left)+g(root.right) + root.val}
// g(root) = f(root.left) + f(root.right)

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
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};

// class Solution {
// public:
//     int tryRob(TreeNode* root, int& l, int& r) {
//         if (!root)
//             return 0;
            
//         int ll = 0, lr = 0, rl = 0, rr = 0;
//         l = tryRob(root->left, ll, lr);
//         r = tryRob(root->right, rl, rr);
        
//         return max(root->val + ll + lr + rl + rr, l + r);
//     }

//     int rob(TreeNode* root) {
//         int l, r;
//         return tryRob(root, l, r);
//     }
// };