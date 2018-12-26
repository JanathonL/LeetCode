class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> lefts;
        int maxlen = 0;
        int last = -1;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                lefts.push(i);
            }
            else{
                if(lefts.empty()){
                    last = i;
                }
                else{
                    lefts.pop();
                    if(lefts.empty()){
                       maxlen = max(maxlen,i-last); 
                    }
                    else{
                        maxlen = max(maxlen,i-lefts.top());
                    }
                }
            }
        }
        return maxlen;
    }
};