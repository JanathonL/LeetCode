92. Reverse Linked List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// refined
// time: O(N)
// space: O(1)
/*
1. get to the new fake head2
2. do the head insert n-m-1 times
3. return real head


 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i =0;i<m-1;i++){
            prev=prev->next;
        }
        ListNode* head2= prev;
        prev=prev->next;
        ListNode* cur=prev->next;
        for(int i =m;i<n;i++){
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next=cur;
            cur = prev->next;
        }
        return dummy.next;
    }
};