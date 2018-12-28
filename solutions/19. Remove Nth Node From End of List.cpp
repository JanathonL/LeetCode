19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        int cnt = 0;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = prev->next;
        
        while(cur!=NULL){
            cnt++;
            cur=cur->next;
        }
        cur = prev->next;
        n = n%cnt;
        if(n!=0) cnt = cnt - n;
        else cnt = 0;
        for(int i=0;i<cnt;i++){
            
            prev=prev->next;
            cur=prev->next;
        }

        prev->next = cur->next;
        delete cur;
        return dummy.next;
    }
};


// refined
// beat 45.09%
// time: O(N) one pass
// space: O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* next = slow->next;
        slow->next = slow->next->next;
        delete(next);
        return dummy.next;
    }
};