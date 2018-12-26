385. Mini Parser
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
     NestedInteger deserialize(string& s, int from, int to) {   
         // cout<<"from:"<<from<<" to:"<<to<<endl;
        if (s[from] != '[') {
            return NestedInteger(stoi(s.substr(from, to - from)));
        }
        
        NestedInteger res;
        from++;
        to--;
        int prev = from, opened = 0;
        for (int i = from; i < to; ++i) {
            if (s[i] == '[') {
                opened++;
            } else if (s[i] == ']') {
                opened--;
            } else if (s[i] == ',' && opened == 0) {
                res.add(deserialize(s, prev, i));
                prev = i + 1;
            }
        }
         
         // cout<<prev<<endl;
        if (prev < to) {
            res.add(deserialize(s, prev, to));
        }
        return res;
    }

    NestedInteger deserialize(string s) {
        return deserialize(s, 0, s.size());
    }
};