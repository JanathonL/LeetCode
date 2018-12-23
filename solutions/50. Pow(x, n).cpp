/*
check n > 0 or not
if n > 0, set x to 1.0/x, n = -n
if n == INT_MIN, use unsigned int
if n%2 == 0
    res = pow(x, n/2)
    return res*res
else 
    res = pow(x, n/2)
    return res*res*x
1 wrong
7 min
time: logn
space: O(logn)  // stack recursive
*/
class Solution {
public:
    double myPow(double x, int n) {
        unsigned num;
        if(n>0){
            num = n;
        } else {
            num = -n;
            x = 1.0/x;
        }
        return pow_recur(x, num);
    }
    double pow_recur(double x, unsigned n){
        if(n==0){
            return 1.0;
        } else if(n==1){
            return x;
        }
        double res = myPow(x, n/2);
        if(n%2==0){
            return res*res;
        } else {
            return res*res*x;
        }
    }
    
};