116. Populating Next Right Pointers in Each Node
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode dummy= TreeLinkNode(-1);
        TreeLinkNode* cur = root;
        TreeLinkNode* pre = &dummy;
        for(;cur;cur=cur->next){
            if(cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        connect(dummy.next);
        
    }
};