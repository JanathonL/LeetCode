2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        ListNode* head=l1;
        ListNode* last = l1;
        int carry = 0;
        while(l1!=NULL&&l2!=NULL){
            l1->val+=l2->val+carry;
            carry = l1->val / 10;
            l1->val = l1->val%10;
            
            last = l1;
            l1=l1->next;
            l2=l2->next;
            
            
        }
        ListNode* tmp= new ListNode(1);
        
        if(l1==NULL&&l2!=NULL){
            last->next=l2;
            l1 = last->next;
            // cout<<l1->next<<endl;
        }
        
        while(l1!=NULL){
            l1->val += carry;
            carry = l1->val / 10;
            l1->val = l1->val%10;
            last = l1;
            l1=l1->next;
        }
        if(carry==1){
            
            
            last->next=tmp;
            return head;
        }
        return head;
        
    }
};