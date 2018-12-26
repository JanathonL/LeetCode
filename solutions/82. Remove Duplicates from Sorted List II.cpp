82. Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        unordered_map<int,int> mymap;
        ListNode* cur = head;
        while(cur!=NULL){
            if(mymap.find(cur->val)==mymap.end()){
                mymap[cur->val] = 1;
            }
            else{
                mymap[cur->val] ++;
            }
            cur=cur->next;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        cur = prev->next;
        while(cur!=NULL){
            // cout<<cur->val<<endl;
            if(mymap[cur->val]>1){
                prev->next = cur->next;
                delete cur;
                
            }
            else{
                prev = prev->next;
            }
            cur = prev->next;
        }
        // cout<<dummy.next<<endl;
        return dummy.next;
    }
};