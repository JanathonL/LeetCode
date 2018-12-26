143. Reorder List
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
    void reorderList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode dummy2(-1);
        dummy2.next = slow->next;
        ListNode* prev = slow->next;
        slow->next = NULL;
        
        ListNode* cur=NULL;
        if(prev) cur = prev->next;
        while(cur){
            ListNode* next = cur->next;
            cur->next = dummy2.next;
            dummy2.next = cur;
            prev->next = next;
            cur = prev->next;
        }
        ListNode* first;
        ListNode* second;
        first=dummy.next;
        second = dummy2.next;
        while(first&&second){
            ListNode* next = first->next;
            ListNode* snext = second->next;
            first->next = second;
            second->next = next;
            first = next;
            second = snext;
        }
        head=dummy2.next;
    }
};