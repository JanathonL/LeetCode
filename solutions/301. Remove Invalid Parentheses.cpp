301. Remove Invalid Parentheses
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            } else if(s[i]==')') {
                if(left>0){
                    left--;
                } else {
                    right++;
                }
            }
        }
        int start = 0;
        unordered_set<string> res;
        string cur;
        int left_cnt = 0;
        backtrack(s, start, res, cur, left_cnt, left, right);
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
    
    void backtrack(string s, int start, unordered_set<string>& res, string cur, 
                   int left_cnt, int left_rem, int right_rem){
        if(start==s.size()){
            if(left_rem==right_rem && left_rem==0){
                res.insert(cur);
            }
            return;
        }
        char c = s[start];
        if(c=='('){
            if(left_rem>0){
                backtrack(s, start+1, res, cur, left_cnt, left_rem-1, right_rem);
            }
            backtrack(s, start+1, res, cur+"(", left_cnt+1, left_rem, right_rem);
        } else if(c==')') {
            if(right_rem>0){
                backtrack(s, start+1, res, cur, left_cnt, left_rem, right_rem-1);
            }
            if(left_cnt>0){
                backtrack(s, start+1, res, cur+")", left_cnt-1, left_rem, right_rem);
            }
        } else {
            backtrack(s, start+1, res, cur+c, left_cnt, left_rem, right_rem);
        }
    }
};