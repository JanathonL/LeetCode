24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = pre->next;
        while(cur!=NULL){
            if(cur->next!=NULL){
                ListNode* tmp = cur->next->next;
                pre->next = cur->next;
                pre->next->next = cur;
                cur->next = tmp;
                pre = cur;
                cur = pre->next;
            }
            else{
                break;
            }
        }
        return dummy.next;
    }
};