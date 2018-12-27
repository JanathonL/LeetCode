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



// refined

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
        int carry = 0;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(l1||l2||carry){
            int temp = 0;
            if(l1){
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2){
                temp += l2->val;
                l2 = l2->next;
            }
            temp += carry;
            carry = temp/10;
            cur->next = new ListNode(temp%10);
            cur = cur->next;
        }
        return dummy.next;
    }
};