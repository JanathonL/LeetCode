// 326. Power of Three
// （1）	不断除以3，看看最后能不能得到1
// （2）	fmod(log10(n)/log10(3),1)==0   这里用log10是因为log的话243会出错
// （3）	直接先求出最大的3的pow，之后mod 3是否等于零，这里要判断一下n>0
class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxv = int(pow(3,(int)(log10(INT_MAX)/log10(3))));
        return n<=0? false : (maxv%n==0);
    }
};
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return fmod((log10(n)/log10(3)),1)==0;
//     }
// };