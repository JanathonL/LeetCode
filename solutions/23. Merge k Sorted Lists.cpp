23. Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        int n = lists.size();
        int cnt = 0;
        while(n>1){
            cnt = 0;
            for(int i =0;i<n-1;i+=2){
                lists[cnt++] = merge2Lists(lists[i],lists[i+1]);
            }
            if(n%2==1){
                lists[cnt++]=lists[n-1];
                n/=2;
                n++;
            }
            else{
                n/=2;
            }
        }
        return lists[0];
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode dummy = ListNode(INT_MIN);
        ListNode* pre = &dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                ListNode* next = l1->next;
                l1->next = pre->next;
                pre->next = l1;
                pre = pre->next;
                l1 = next;
            }
            else{
                ListNode* next = l2->next;
                l2->next = pre->next;
                pre->next = l2;
                pre = pre->next;
                l2 = next;
            }
        }
        pre->next = l1? l1:l2;
        return dummy.next;
    }
};