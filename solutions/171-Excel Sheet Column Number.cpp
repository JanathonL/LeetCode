// 171. Excel Sheet Column Number
// 注意一下c-‘A’+1就可以了
// ans = ans*26 + c-‘A’ +1

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(auto c:s){
            ans = ans*26 + c-'A'+1;
        }
        return ans;
    }
};