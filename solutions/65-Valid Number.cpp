// 65-Valid Number
// 顺序判断一下几个步骤
// （1）	去除leading的空格
// （2）	判断是否有符号
// （3）	判断数字部分是否小数点只有1位或者没有，而且得有至少一个digit
// （4）	如果有e，就判断指数部分，先判断有没有符号，然后判断是否至少有一个digit
// （5）	去除后面的空格
// （6）	最后如果该字符串是到达了最后的‘\0’，那么就true，否则false

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while(s[i]==' ') i++;
        if(s[i]=='+'||s[i]=='-') i++;
        int num_p,num_d;
        num_p=num_d=0;
        while(s[i]<='9'&&s[i]>='0'||s[i]=='.') {
            if(s[i]=='.'){
                num_p++;
            }
            else{
                num_d++;
            }
            i++;
        }
        if(num_p>1||num_d<1) return false;
        
        if(s[i]=='e'){
            i++;
            if(s[i]=='+'||s[i]=='-'){
                i++;
            }
            num_d=0;
            while(s[i]>='0'&&s[i]<='9') {
                num_d++;
                i++;
            }
            if(num_d<1) return false;
        }
        while(s[i]==' ') i++;
        return s[i]=='\0';
    }
    
    
};