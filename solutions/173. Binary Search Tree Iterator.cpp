173. Binary Search Tree Iterator
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
20 min 
can not solve
-------------
5 min
bug free
space: O(N)
*/
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        find_left(root);  
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {  // O(1)
        if(!stk.empty()){
            return true;
        } else {
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {  // avg O(1)
        TreeNode* cur = stk.top();
        int res = cur->val;
        stk.pop();
        find_left(cur->right);
        return res;
    }
    void find_left(TreeNode* cur){
        while(cur||!stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                break;
            }
        }
    }
stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */