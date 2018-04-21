// 237. Delete Node in a Linked List
// 无语的题，直接*node=*node->next也能过。。。
// 好一点的方法是把下一个节点删了
// auto next = node->next;
// node*=*next;
// delete next;

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
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};