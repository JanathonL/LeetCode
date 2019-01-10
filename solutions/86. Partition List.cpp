86. Partition List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        while(pre->next!=NULL && pre->next->val<x){
            pre = pre->next;
        }
        ListNode* head2 = pre;
        pre = pre->next;
        while(pre!=NULL&&pre->next!=NULL){
            if(pre->next->val < x){
                ListNode* tmp = head2->next;
                head2->next = pre->next;
                pre->next = pre->next->next;
                head2->next->next = tmp;
                head2 = head2->next;
            }
            else{
                pre=pre->next;
            }
            
        }
        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// refined
// beat 37%
// time: O(N)
// space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1), dummy2(-1);
        dummy1.next = head;
        ListNode* pre = &dummy1, *cur = head, *new_cur = &dummy2;
        while(cur!=NULL){
            if(cur->val<x){
                new_cur->next = cur;
                new_cur = new_cur->next;
                pre->next = cur->next;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        new_cur->next = dummy1.next;
        return dummy2.next;
    }
};