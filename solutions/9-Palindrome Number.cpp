// 9. Palindrome Number
// 负数的话直接return false
// 可以直接把这个数字转成字符串，然后直接正反对比
// 另一种的解法是，不断地取第一位和最后一位（10进制下）进行比较，相等则取第二位和倒数第二位，直到完成比较或者中途找到了不一致的位。
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s;
        while(x!=0){
            int tail = x%10;
            s += tail + '0';
            x/=10;
        }
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s2==s;
    }
};
