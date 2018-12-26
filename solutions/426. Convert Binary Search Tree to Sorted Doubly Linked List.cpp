/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    /*
    stack<Node*> stk

    push left to stk
    pop and push cur->right to stk
    
    prev = NULL
    prev->right = cur
    cur->left = prev
    if(prev==NULL) {
        set head
        set prev
    }
    prev = cur
        4
      /  \
    2     5
   / \
  1  3
  stk: 
  head = 1
  prev = 5
  cur = NULL
  1 <-> 2 <-> 3 <-> 4 <-> 5
  14 min
  bug free
  Time: O(N)
  space: O(H)
    */
    Node* treeToDoublyList(Node* root) {
        // check empty
        if(root==NULL){
            return NULL;
        }
        stack<Node*> stk;
        Node* cur = root;
        Node* head = NULL;
        Node* prev = NULL;
        while(cur||!stk.empty()){
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if(prev==NULL){
                    prev = cur;
                    head = cur;
                } else {
                    prev->right = cur;
                    cur->left = prev;
                    prev = cur;
                }
                cur = cur->right;
            }
        }
        head->left = prev;
        prev->right = head;
        return head;
    }
    
};