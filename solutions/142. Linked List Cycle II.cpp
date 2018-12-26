142. Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;

        ListNode dummy=ListNode(-1);
        dummy.next = head;
        ListNode* faster = &dummy;
        ListNode* slower = &dummy;
        while(faster&&faster->next){
            faster=faster->next->next;
            slower=slower->next;
            if(faster == slower) {
                ListNode* slower2 = &dummy;
                while(slower2!=slower){
                    slower2=slower2->next;
                    slower=slower->next;
                }
                return slower2;
            }
        }
        return NULL;
    }
};