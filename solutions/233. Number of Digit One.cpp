// 233. Number of Digit One
// https://blog.csdn.net/wzy_1988/article/details/47148263
// 在面试过程中如果被问到类似的题目，一定不要着急，因为这肯定是一道找规律的题目。最好的办法是在白纸上写一个差不多大的数，然后分析如何计算每一位1出现的次数。

// 以24071为例，如果我们想计算百位上1出现的次数，具体思路如下：

// 获取百位的高位为24，获取百位的低位为71，当前百位数字为0。
// 从高位出发来分析，百位出现的次数有：00100~00190,01100~01190,02100~02190,…,23100~23190。总共有(24*100)个1出现。
// 这是百位为0的情况，
// 如果百位为1的时候，那除了上述的(24*100)个1之外，还包括：24100～24171，共(71 + 1)个1，即总共：24 * 100 + 71 + 1。

// 如果百位大于1例如为6的时候，那除了最开始的(24*100)个1之外，还包括了：24100~24199，共100个1，即总共：(24 + 1)*100。

// 总结规律

// 其实通过上面的分析，我们就可以归纳出一个规律如下。

// 要求第i位1出现的次数，并且i的高位数为highN，低位数为lowN，当前第i位的数字为cdigit，则当前i位1出现的次数分三种情况：

// cdigit == 0, count = highN * factor.
// cdigit == 1, count = highN * factor + lowN + 1.
// cdigit > 1, count = (highN + 1) * factor.
// 其中，factor为当前的乘积因子，例如百位的factor为100，十位的乘积因子为10。

// 有了规律，代码只要按照规律写出来即可。

class Solution {
public:
    int countDigitOne(int n) {
        long cur,highn,lown,factor;
        factor=1;
        cur=n%factor;
        long res=0;
        while(n/factor>0){
            cur = n/factor%10;
            highn = n/factor/10;
            lown = n%factor;
            if(cur==0) res+=highn*factor;
            else if(cur==1) res+=highn*factor+lown+1;
            else {
                res+= (highn+1)*factor;
            }
            factor*=10;
        }
        return res;
        
        
    }
};