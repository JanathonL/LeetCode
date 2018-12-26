508. Most Frequent Subtree Sum
/*
DP for tree
post order traverse the tree
maxfrequent 

ls = left node sub sum
rs = right node sub sum
sum = root->val + ls + rs
map[sum] ++;
return sum

traverse the map to find the most frequent sum(s)

Tree=[5,2,-3]
sum = [2,-3,4]
max_frequent = 1
res = [2,-3,4]

Tree=[5,2,-5]
sum = [2,-5,2]
max_frequent = 2
res = [2]

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int max_frequent = 0;
        helper(m, root, max_frequent);
        vector<int> res;
        for(auto it:m){
            if(max_frequent==it.second){
                res.push_back(it.first);
            }
        }
        return res;
    }
    int helper(unordered_map<int, int>& m, TreeNode* root, int& max_frequent){
        if(!root) return 0;
        int ls = 0;
        int rs = 0;
        ls = helper(m,root->left, max_frequent);
        rs = helper(m, root->right, max_frequent);
        int sum = root->val + ls + rs;
        m[sum]++;
        max_frequent = max(m[sum], max_frequent);
        return sum;
    }
};