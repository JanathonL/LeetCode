24. Swap Nodes in Pairs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// refined
// beat 100%
// time: O(N)
// space: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        
        while(cur&&cur->next){
            ListNode* next = cur->next->next;
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = next;
            pre = cur;
            cur = next;
        }
        return dummy.next;
    }
};