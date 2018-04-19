// 203. Remove Linked List Elements
// 链表题，定义一个dummy指向head，然后定义一个pre,cur方便删除。注意while循环的时候要对pre和cur更新

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->val==val){
                pre->next = cur->next;
                cur = pre->next;
                continue;
            }
            pre = cur;
            cur = pre->next;
        }
        return dummy.next;
    }
};