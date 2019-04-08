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



// refined
// no trick
// time: O(N)
// space: O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        TreeLinkNode* pre_next=root, *cur_next=root->left;
        while(cur_next){
            while(pre_next){
                pre_next->left->next = pre_next->right;
                if(pre_next->next) {
                    pre_next->right->next = pre_next->next->left;
                }
                pre_next = pre_next->next;
            }
            pre_next = cur_next;
            cur_next = cur_next->left;
        }
    }
};


// refined
// level order with push NULL trick
// time: O(N)
// space: O(N)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root); q.push(NULL);
        
        while(true){
            TreeLinkNode *cur = q.front();
            q.pop();
            
            if(cur){
                cur->next = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }else {
                if (q.size() == 0 || q.front() == NULL) return;
                q.push(NULL);
            }
        }
        
    }
};