148. Sort List
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
    void print_ListNode(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    ListNode* merge(ListNode* head, ListNode* head2){
        // print_ListNode(head);
        // print_ListNode(head2);
        
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        while(head || head2){
            if(head&&head2){
                if(head->val < head2->val){
                    cur->next = head;
                    cur = cur->next;
                    head = head->next;
                } else {
                    cur->next = head2;
                    head2 = head2->next;
                    cur = cur->next;
                }
            } else if(head){
                cur->next = head;
                break;
            } else {
                cur->next = head2;
                break;
            }
        }
        // print_ListNode(dummy.next);
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        // find mid
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        // sort first half and second half
        head = sortList(head);
        head2 = sortList(head2);
        // merge two half
        head = merge(head, head2);
        return head;
    }
};