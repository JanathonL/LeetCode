// 172. Factorial Trailing Zeroes
// 要考虑到末尾的零主要是由于10才产生的，
// 而10是由5这个因子产生的，
// 由于2的倍数比5远远要多，所以只要考虑5的个数就好了，
// 但是由于25这种的存在，它会多出一个5的因子，所以还要考虑5^k次，最后代码就很简单了
// res+=n/5^k
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(long long i =5;n/i>0;i*=5){
            res+=n/i;
        }
        return res;
        
    }
};