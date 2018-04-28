// 341. Flatten Nested List Iterator
// 递归
// 遍历当前nestedlist，判断某个nl[i]是否是int，是的话就push到一个队列中，否则就递归。

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    void helper(vector<NestedInteger> &nl){
        for(int i=0;i<nl.size();i++){
            if(nl[i].isInteger()){
                q.push(nl[i].getInteger());
            }
            else{
                helper(nl[i].getList());
            }
        }
    }

    int next() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    bool hasNext() {
        return q.size()>0;
    }
private:
    queue<int> q;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */