844. Backspace String Compare

// refined stack beat 100%
// time: O(m+n)
// space: O(n+m)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk1, stk2;
        for(char c:S){
            if(c=='#'){
                if(stk1.empty()) continue;
                stk1.pop();
            } else {
                stk1.push(c);
            }
        }
        for(char c:T){
            if(c=='#'){
                if(stk2.empty()) continue;
                stk2.pop();
            } else {
                stk2.push(c);
            }
        }
        return stk1==stk2;   
    }
};


// two pointer
// refined beat 100%
// time: O(m+n)
// space: O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int ptr1, ptr2;
        
        ptr1 = S.size()-1;
        ptr2 = T.size()-1;
        int cnt1 = 0, cnt2 = 0;
        while(ptr1>=0 || ptr2>=0){
            while(ptr1>=0){
                if(S[ptr1]=='#') {
                    cnt1++;
                    ptr1--;
                } else if (cnt1>0) {
                    cnt1--;
                    ptr1--;
                } else {
                    break;
                }
            }
            while(ptr2>=0){
                if(T[ptr2]=='#') {
                    cnt2++;
                    ptr2--;
                } else if (cnt2>0) {
                    cnt2--;
                    ptr2--;
                } else {
                    break;
                }
            }
            if(ptr1>=0&&ptr2>=0&&S[ptr1]!=T[ptr2]){
                return false;
            }
            if((ptr1>=0) != (ptr2>=0)){
                return false;
            }
            ptr1--;
            ptr2--;
        }
        return true;
        
        
    }
};