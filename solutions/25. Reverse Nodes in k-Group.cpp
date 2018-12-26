25. Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy(-1);
        // dummy
        // 先把总的节点数cnt算出来，然后一段一段去用头插法的方式reverse(每段插完就更新head2)，最后一段的时候判断一下cnt-cur_cnt是否小于k，不是的话就保留
        int cnt = 0;
        dummy.next = head;
        ListNode* pre = &dummy;
        while(pre->next!=NULL){
            pre = pre->next;
            cnt++;
        }
        // printNode(head);
        ListNode* head2 = &dummy;
        int cnt_tmp = 1;
        while(cnt>=k){
            cnt_tmp = 1;
            head2= reverseK(head2,k);
            cnt -= k;
            // cout<<"cnt:"<<cnt<<endl;
            // printNode(head);
        }
        
        return dummy.next;
    }
    void printNode(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    ListNode* reverseK(ListNode* head, int k){
        if(k==1) return head->next;
        ListNode* pre = head;
        ListNode* head2 = pre->next;
        ListNode* cur = pre->next->next;
        int cnt = 1;
        
        while(cnt<k-1){
            
            ListNode* tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = tmp;
            cnt++;
            // cout<<cnt<<endl;
        }
        // printNode(head);
        ListNode* tmp = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        head2->next = tmp;
        // printNode(head);
        return head2;
    }
};