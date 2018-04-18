// 168. Excel Sheet Column Title
// 注意一下n在mod 26之前先 n-=1;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n!=0){
            n -= 1;
            res += (n)%26+'A';
            
            n/=26;
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};