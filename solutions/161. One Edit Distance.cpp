/*
8 min
bug free
time: O(min(n,m))
space: O(1)
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(abs(n-m)>1){
            return false;
        }
        if(n < m){
            return isOneEditDistance(t, s);
        }
        // traverse the short path
        int cnt = 0;
        int j = 0;
        for(int i=0;i<n;){
            if(t[j] != s[i]){
                if(n != m){
                    i += 1;
                } else {
                    i++;
                    j++;
                }
                cnt++;
                if(cnt>1){
                    return false;
                }
            } else{
                i++;
                j++;
            }
        }
        return cnt==1;
    }
};