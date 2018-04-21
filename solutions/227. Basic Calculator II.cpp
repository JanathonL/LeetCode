// 227. Basic Calculator II
// 用一个stringstream in来处理会非常简单
// 下一个数字直接就是 in>>term
// 然后注意一下，只有遇到’+’ ‘-‘才往结果里加入term，而且要把下一个term的符号用正负标记上，所有的乘法除法计算都是在term上计算。

class Solution {
public:
    int calculate(string s) {
        stringstream in('+'+s+'+');
        char op;
        int res=0,term=0,n;
        while(in>>op){
            if(op=='+'||op=='-'){
                res+=term;
                in>>term;
                term *= op=='+'? 1:-1;
            }
            else{
                in>>n;
                if(op=='*'){
                    term*=n;
                }
                else if(op=='/'){
                    term/=n;
                }
            }
        }
        return res;
        
    }
};