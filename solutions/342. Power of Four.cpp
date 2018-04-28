// 342. Power of Four
// 简单的方法是，先统计低位0的个数，然后看看剩余的数是不是1.
// （1）	由于输入是int，正数范围是0-231，在此范围中允许的最大的4的次方数，那么我们只要看这个数能否被n整除即可
// （2）	使用换底公式，看看int(log10(n) / log10(4)) - log10(n) / log10(4) == 0
// （3）	return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
// !(num&(num-1)) 判断是否是2的倍数
// 4的次方数的最高位的1都是计数位，那么我们只需与上一个数(0x55555555) <==> 1010101010101010101010101010101，如果得到的数还是其本身，
// 则可以肯定其为4的次方数
// （4）	或者我们在确定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除
// return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;

// We know from Binomial Theroem that (1+X)^n = C(n,0) + C(n,1)*X + C(n,2)*X^2 + C(n,3)*X^3 +.........+ C(n,n)*X^n
// Put X=3, we get 4^n = 1 + C(n,1)*3 + C(n,2)*3^2 + C(n,3)*3^3 +.........+ C(n,n)*3^n
// by moving 1 left side, we get 4^n - 1 = C(n,1)*3 + C(n,2)*3^2 + C(n,3)*3^3 +.........+ C(n,n)*3^n
// i.e (4^n - 1) = 3 * [ C(n,1) + C(n,2)*3 + C(n,3)*3^2 +.........+ C(n,n)*3^(n-1) ]
// This implies that (4^n - 1) is multiple of 3.
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0){
            return false;
        }
        int cnt=0;
        while(true){
            int newn=num>>1;
            if((newn<<1)==num){
                // cout<<newn<<" "<<num<<endl;
                num=newn;
                cnt++;
            }
            else{
                break;
            }
        }
        // cout<<cnt<<" "<<num<<endl;
        if(cnt%2==0&&num==1){
            return true;
        }
        else{
            return false;
        }
    }
};
