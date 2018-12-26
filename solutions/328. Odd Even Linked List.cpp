328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        int cnt = 1;
        if(head==NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        if(p2==NULL) return head;
        ListNode* p3 = p1->next;
        ListNode* p4 = p3->next;
        if(p4==NULL) return head;
        cnt = 3;
        while(1){
            p1->next = p4;
            p3->next = p4->next;
            p4->next = p2;
            p1=p4;
            p3=p3->next;
            if(p3==NULL) break;
            p4=p3->next;
            if(p4==NULL) break;
        }
        return head;
        
        
    }
};