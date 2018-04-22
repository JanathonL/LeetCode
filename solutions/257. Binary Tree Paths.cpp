// 257. Binary Tree Paths
// 直接遍历一下树就可以了，注意要判断一下是否是叶子节点，是的话才把当前path记录下来。

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        pre(root,path);
        for(auto item:paths){
            string tmp;
            for(auto i:item){
                if(tmp=="")
                    tmp+=to_string(i);
                else{
                    tmp+="->";
                    tmp+=to_string(i);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    void pre(TreeNode* root, vector<int> path){
        if(!root) {
            return ;
        }
        
        path.push_back(root->val);
        if(root->right==nullptr&&root->left==nullptr){
            paths.push_back(path);
        }
        pre(root->left,path);
        pre(root->right,path);
        path.pop_back();
    }
private:
    vector<vector<int>> paths;
};