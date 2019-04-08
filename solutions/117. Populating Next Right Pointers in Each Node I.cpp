117. Populating Next Right Pointers in Each Node II
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

//refined
// time: O(N)
// space:O(H)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode dummy(-1);
        TreeLinkNode* cur = root;
        TreeLinkNode* pre = &dummy;
        for(;cur;cur=cur->next){
            if(cur->left){
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right){
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        connect(dummy.next);
    }
};
// /**
//  * Definition for binary tree with next pointer.
//  * struct TreeLinkNode {
//  *  int val;
//  *  TreeLinkNode *left, *right, *next;
//  *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         queue<TreeLinkNode*> cur,next;
//         if(!root) return;
//         cur.push(root);
//         TreeLinkNode* pre = nullptr;
//         while(!cur.empty()){
//             pre = nullptr;
//             while(!cur.empty()){
//                 TreeLinkNode* tmp = cur.front();
//                 cur.pop();
//                 if(pre==nullptr) {
//                     pre = tmp;
//                 }
//                 else{
//                     pre->next = tmp;
//                     pre = tmp;
//                 }
//                 if(tmp->left) next.push(tmp->left);
//                 if(tmp->right) next.push(tmp->right);
                
//             }
//             pre->next = nullptr;
//             swap(cur,next);
//         }
//     }
// };