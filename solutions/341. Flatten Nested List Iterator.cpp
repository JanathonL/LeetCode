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
    typedef vector<NestedInteger>::iterator Iter;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        // hasNext();
        return (stk.top().first++)->getInteger();
    }

    bool hasNext() {
        while (stk.size()) {
            auto cur = stk.top();
            if (cur.first == cur.second) {
                stk.pop();
            } else {
                auto x = cur.first;
                if (x->isInteger())
                    return true;
                (stk.top().first)++;
                // auto ni_list = x->getList();  // ?????????????????
                stk.push({x->getList().begin(), x->getList().end()});
                // stk.push({ni_list.begin(),ni_list.end()});
            }
        }
        return false;
    }

private:
    // stack<Iter> begins, ends;
    stack<pair<Iter, Iter>> stk;
};
// class NestedIterator {
// public:
//     /*
//     get the interator
//     stack<pair<iter,enditer>> stk
//     while(!stk.empty() && stk.top().first is not int){
//         cur = stk.top()
//         stk.pop()
//         update cur// cur.first++
//         get list
//         push(cur)
//         push(new list) 
//     }
//     cannot find problem
//     1 hour
    
//     */
//     typedef vector<NestedInteger>::iterator Iter;
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         stk.push({nestedList.begin(), nestedList.end()});        
//     }

//     int next() {
//         pair<Iter, Iter> cur = stk.top();
//         int res = (cur.first)->getInteger();
//         (stk.top().first)++;
//         return res;
//     }

//     bool hasNext() {
//         while(!stk.empty()){
//             cout<<"test"<<endl;
//             pair<Iter, Iter> cur = stk.top();
//             if(cur.first==cur.second){
//                 stk.pop();
//                 cout<<"pop"<<endl;
//                 continue;
//             } else {
//                 Iter begin = cur.first;
//                 if(begin->isInteger()){
//                     cout<<begin->getInteger()<<endl;
//                     return true;
//                 } else {
//                     // cout<<begin->getInteger()<<endl;
//                 }
//                 (stk.top().first)++;
//                 vector<NestedInteger> ni_list = begin->getList();
                
//                 stk.push({ni_list.begin(), ni_list.end()});
//             }
            
//             // if(ni_list.begin()->isInteger()){
//             //     cout<<ni_list.begin()->getInteger()<<endl;
//             // }
//         }
//         return false;
//     }

//     stack<pair<Iter, Iter>> stk;
    
// };

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */