// 273. Integer to English Words
// 可以巧妙地利用递归完成这个数字的转换
// if(num>=1000000000) return cal(num/1000000000)+" Billion"+cal(num%1000000000);
// 只需关注最后19个数字还有100以内的几十是需要额外自己定义的。
// 注意末尾如果是0的话不要输出Zero, 20这种只要输出 Twenty。 
// 注意额外判断一下0是返回Zero
// 注意最后返回的时候把开头的“ ”舍去。return cal(num).substr(1);
class Solution {
public:
    //2147483647
    string numberToWords(int num) {
        if(num==0) return "Zero";
        return cal(num).substr(1);
    }
    string cal(int num){
        if(num>=1000000000) return cal(num/1000000000)+" Billion"+cal(num%1000000000);
        else if(num>=1000000) return cal(num/1000000)+" Million"+cal(num%1000000);
        else if(num>=1000) return cal(num/1000)+" Thousand"+cal(num%1000);
        else if(num>=100) return cal(num/100)+" Hundred"+cal(num%100);
        else if(num>=20) return string(" ")+decimas[num/10-2]+cal(num%10);
        else if(num>=1) return string(" ")+digits[num];
        else return "";
    }
private:
    string digits[20]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
                         "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string decimas[8]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
};