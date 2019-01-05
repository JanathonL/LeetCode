61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int cnt = 0;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = &dummy;
        cur = cur->next;
        while(cur!=NULL){
            cnt++;
            cur=cur->next;
        }
        k = k % cnt;
        cnt = cnt-k;
        cur = &dummy;
        for(int i = 0;i<cnt;i++){
            cur = cur->next;
        }
        if(cur->next!=NULL){
            // cur = cur->next;
            dummy.next = cur->next;
            cur->next = NULL;
            cur=dummy.next;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            cur->next = head;
            return dummy.next;
        }
        else{
            return dummy.next;
        }
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
// beat 20.36%
// time:O(N)
// space:O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* h = head, *tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        
        tail->next = h;
        k %= len;
        for(int i=0;i<len-k;i++){
            tail = tail->next;
        }
        h = tail->next;
        tail->next = NULL;
        return h;
    }
};