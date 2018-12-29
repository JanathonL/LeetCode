listnode operations

trick 1:
find tail and reconnect the list: tail->next = head
solve the problem: 61. Rotate List
trick 2:
slow and fast pointers
* find the middle of list
* find kth node from the end

operations:
reverse:
		* iterative(normal)
		ListNode* reverseList(ListNode* head) {
		    ListNode* prev = NULL;
		    ListNode* cur = head;
		    while(cur!=NULL){
		        ListNode* next = cur->next;
		        cur->next = prev;
		        prev = cur;
		        cur = next;
		    }
		    return prev;
		}
		* iterative(insert to head)
		ListNode* reverseList(ListNode* head) {
		    ListNode dummy(-1);
		    ListNode *pre = &dummy, *cur = head;
		    dummy.next = head;
		    while (cur && cur -> next) {
		        ListNode* next = cur -> next;
		        cur -> next = cur -> next -> next; 
		        next -> next = pre->next;
		        pre -> next = next;
		    }
		    return dummy.next;
		}
		* recursive
		ListNode* reverseList(ListNode* head) {
		    if(head==NULL || head->next==NULL){
		        return head;
		    }
		    ListNode* new_head = reverseList(head->next);
		    head->next->next = head;
		    head->next = NULL;
		    return new_head;
		}




