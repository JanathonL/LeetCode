// 29. Divide Two Integers
// // Time O(logn)，Space O(1)
// 不能用乘法，除法和mod，那么只能用原始的减法了。
// 这题直接用减法会超时，可以利用divisor*2来加速。
// 注意一下，这题会有溢出的可能性，当INT_MIN/-1的时候会溢出
// 然后可以把所有的case都转换成dividend<0 && divisor<0来做，因为正数转换成负数不会溢出。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&& divisor==-1){
            return INT_MAX;
        }
        int cnt=0;
        int flag = 1;
        if(divisor<0&&dividend>0 || divisor>0&&dividend<0) flag = -1;
        if(dividend==0) return 0;
        if(dividend>0&&divisor<0){
            dividend = -dividend;
        }
        else if(dividend<0&& divisor>0){
            divisor = -divisor;
        }
        else if(dividend>0&&divisor>0){
            dividend = -dividend;
            divisor = -divisor;
        }
        
        if(dividend<0&&divisor<0){
            while(dividend<=divisor){
                int tmp = divisor;
                for(int i =0; dividend<=tmp;){
                    dividend-=tmp;
                    cnt += 1 << i;
                    if(tmp> INT_MIN/2){
                        tmp *= 2;
                        i++;
                    }
                }
                
            }
            return cnt*flag;
        }
        
        
        
    }
};