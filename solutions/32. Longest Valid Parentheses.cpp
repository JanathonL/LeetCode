// refined 
// time: O(N)
// space: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left;
        int res = 0, last = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left.push(i);
            } else {
                if(!left.empty()){
                    left.pop();
                    if(!left.empty()){
                        res = max(res, i-left.top());
                    } else {
                        res = max(res, i-last);
                    }
                } else {
                    last = i;
                }
            }
        }
        return res;
    }
};