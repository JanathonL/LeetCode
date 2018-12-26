105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = build(0,preorder.size()-1,0,preorder,inorder);
        return root;
    }
    TreeNode* build(int low, int high,const int cur, vector<int> preorder, vector<int> inorder){
        TreeNode* root = nullptr;
        // cout<<"low:"<<low<<" high:"<<high<<" cur:"<<cur<<endl;
        if(cur>=preorder.size()) return nullptr;
        if(high == low){
            TreeNode* root = new TreeNode(preorder[cur]);
            return root;
        }
        if(high<low) return nullptr;
        int ind = -1;
        for(int i = low;i<=high;i++){
            if(inorder[i]==preorder[cur]){
                ind = i;
                break;
            }
        }
        int leftsize = ind-low;
        root = new TreeNode(preorder[cur]);
        cout<<root->val<<endl;
        root->left = build(low,ind-1,cur+1,preorder,inorder);
        root->right = build(ind+1,high,cur+leftsize+1,preorder,inorder);
        return root;
    }
};