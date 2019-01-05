29. Divide Two Integers
/*
wrong 1 time
time 11min
time: (log n)^2
space: 1
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        int mul = 1;
        int sign = 1;
        if(dividend == 0) return 0;
        if(dividend<0&&divisor>0 || dividend>0&&divisor<0){
            sign = -1;
        }
        unsigned divid = dividend>0? dividend:-dividend;
        unsigned dis = divisor>0? divisor:-divisor;
        unsigned mask = 1<<31;
        while(divid>=dis){
            unsigned old = dis;
            while(!(dis&mask) && divid>dis<<1){
                dis = dis<<1;
                mul = mul<<1;
            }
            divid -= dis;
            res += mul;
            mul = 1;
            dis = old;
        }
        if(res==INT_MIN){
            return sign==1? INT_MAX:INT_MIN; 
        }
        return res*sign;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0) return 0;
        
        long divd = dividend, divs = divisor, l = 0, r;
        if ((divd > 0 && divs > 0) || (divd < 0 && divs < 0))
            r = abs(divd) + 1;
        else r = -abs(divd) - 1;
        
        while (abs(r - l) > 1) {      // 这里要abs(r-l) > 1, 这样才不会被卡死
            long mid = (l + r) / 2;
            if (abs(mid * divs) == abs(divd)) return (int)mid;
            else if (abs(mid * divs) < abs(divd)) l = mid;
            else r = mid;
        }
        return (int)l;
    }
};