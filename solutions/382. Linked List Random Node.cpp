// 382. Linked List Random Node
// 蓄水池采样
// public int[] selectKItems(int[] stream, int k) {
//         int[] reservoir = new int[k];
//         int i = 0;
//         for (; i < k; i++) {
//             reservoir[i] = stream[i];
//         }
//         Random rand = new Random();
        
//         while (i < stream.length) {
//             int j = rand.nextInt(i + 1);
//             if (j < k) {
//                 reservoir[j] = stream[i];
//             }
//             i++;
//         }
//         return reservoir;
//     }


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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int reservoir = head->val;
        int i = 1;
        ListNode* node = head->next;
        while(node){
            int j = int(rand()%(++i));
            if(j<1){
                reservoir = node->val;
            }
            node=node->next;
        }
        return reservoir;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */