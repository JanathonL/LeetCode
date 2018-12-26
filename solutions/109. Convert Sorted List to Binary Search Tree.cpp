109. Convert Sorted List to Binary Search Tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
    TreeNode* build(ListNode* head){
        TreeNode* root=nullptr;
        if(!head) return nullptr;
        // cout<<"head:"<<head->val<<endl;
        if(!head->next) return new TreeNode(head->val);
       
        ListNode* pre = head;
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = nullptr;
        
        // cout<<slow->val<<endl;
        root = new TreeNode(slow->val);
        root->left = build(head);
        root->right = build(slow->next);
        return root;
    }
};