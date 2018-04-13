// 7. Reverse Integer
// 这题注意判断一下overflow
// （newans-x%10）/10 != ans 这样可以来判断是否overflow

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int newans = 0;
        while(x!=0){
            
            newans = ans*10 + x%10;
            if((newans-x%10)/10 != ans) return 0;
            ans = newans;
            x/=10;
        }
        return ans;
        
    }
};