106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(0,inorder.size()-1,postorder.size()-1,inorder,postorder);
        return root;
    }
    TreeNode* build(int low,int high, int cur, vector<int>& inorder, vector<int>& postorder){
        TreeNode* root = nullptr;
        // cout<<"low:"<<low<<" high:"<<high<<" cur:"<<cur<<endl;
        if(cur<0) return nullptr;
        if(low==high){
            root = new TreeNode(postorder[cur]);
            return root;
        }
        if(low>high){
            return nullptr;
        }
        int ind=-1;
        for(int i=low;i<=high;i++){
            if(inorder[i]==postorder[cur]){
                ind = i;
                break;
            }
        }
        int rightsize = high-ind;
        root = new TreeNode(postorder[cur]);
        root->left = build(low,ind-1,cur-rightsize-1,inorder,postorder);
        root->right = build(ind+1,high,cur-1,inorder,postorder);
        return root;
    }
    
};

// refined
// beat: 9%
// time: O(n^2) ?? time: O(NlogN)
// space: O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int cur = postorder.size()-1;
        TreeNode* root = build(0,postorder.size()-1,cur,postorder,inorder);
        return root;
    }
    TreeNode* build(int low, int high,int& cur, vector<int> postorder, vector<int> inorder){
        TreeNode* root = nullptr;
        if(cur>=postorder.size()) return nullptr;
        if(high == low){
            TreeNode* root = new TreeNode(postorder[cur--]);
            return root;
        }
        if(high<low) return nullptr;
        int ind = -1;
        for(int i = low;i<=high;i++){
            if(inorder[i]==postorder[cur]){
                ind = i;
                break;
            }
        }
        root = new TreeNode(postorder[cur--]);
        root->right = build(ind+1,high,cur,postorder,inorder);
        root->left = build(low,ind-1,cur,postorder,inorder);
        return root;
    }
};