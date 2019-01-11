99. Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        inorder(root);
        // cout<<p1->val<<" "<<p2->val<<endl;
        swap(p1->val,p2->val);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        cur = root;
        // cout<<cur->val<<endl;
        if(pre && pre->val > cur->val){
            if(p1==nullptr){
                p1 = pre;
                p2 = cur;
            }
            else{
                p2 = cur;
            }
        }
        pre = cur;
        
        inorder(root->right);
    }
private:
    TreeNode* p1=nullptr;
    TreeNode* p2=nullptr;
    TreeNode* pre = nullptr;
    TreeNode* cur = nullptr;
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// refined
// time: O(N)
// space: O(H)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first, *second, *prev;
        first = second = prev = NULL;
        inorder(root, first, second, prev);
        if(first&&second)
            swap(first->val, second->val);
    }
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev){
        if(root==NULL){
            return;
        }
        inorder(root->left, first, second, prev);
        if(prev==NULL){
            prev = root;
        } else {
            if(root->val <= prev->val){
                if(first==NULL){
                    first = prev;
                    second = root;
                } else {
                    second = root;
                    return;
                }
            }
            prev = root;
        }
        inorder(root->right, first, second, prev);
        
    }
};