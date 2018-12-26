147. Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy = ListNode(INT_MIN);
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            pre = &dummy;
            while(pre->next!=nullptr && pre->next->val < cur->val){
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur=next;
        }
        return dummy.next;
    }
};