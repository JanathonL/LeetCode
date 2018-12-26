397. Integer Replacement
class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        unsigned num = n;
        while(num!=1){
            if(num==3){
                return cnt+2;
            }
            // cout<<hex;
            // cout<<num<<endl;
            cnt ++;
            // if(n==INT_MAX){
            //     n -= 1;
            //     continue;
            // }
            
            if((num&1)){
                if(num&2){
                    num+=1;
                }
                else{
                    num-=1;
                }
            }
            else{
                num=num>>1;
            }
        }
        return cnt;
    }
};