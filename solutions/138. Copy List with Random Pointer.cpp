138. Copy List with Random Pointer
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
3 wrongs
18 min
time: O(N)
space: O(1)  // no extra space
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return head;
        }
        RandomListNode* cur = head;
        RandomListNode* new_head;
        // construct the node
        while(cur){
            RandomListNode* next_node = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next_node;
            cur = next_node;
        }
        new_head = head->next;
        cur = head;   // 别忘了reset cur
        // copy random list
        while(cur){
            if(cur->random != NULL){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;  // 别忘了reset cur
        // recover
        while(cur){
            RandomListNode* next_node = cur->next;
            cur->next = cur->next->next;
            if(next_node->next != NULL){
                next_node->next = next_node->next->next;
            }
            cur = cur->next;
        }
        return new_head;
    }
};