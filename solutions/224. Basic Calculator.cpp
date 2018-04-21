// 224. Basic Calculator
// 使用两个stack, nums和ops. 分别记录上一个括号内的结果
// 使用num记录当前数字，res记录这个括号内的结果，sign记录上一个符号（1，-1）
// 当str[i] == ‘+’
// res += num*sign;
// num = 0;
// sign = 1;  // 表示下一个数字的符号
// 当 str[i]==’(‘
// nums.push(res);
// ops.push(sign);
// res = 0; //记录当前括号结果，重新为零
// sign =1;// sign重新置为1
// 当 str[i]==’)’
// 		res += nums*sign;    //把最后的末尾数字加起来
// //把当前括号里的值与上一个括号的相加，恢复到上一个括号
// res = res*ops.top() + nums.top();    
// ops.pop(); nums.pop();
class Solution {
public:
    int calculate(string str) {
        stack<int> nums,ops;
        int n = str.size();
        if(n==0) return 0;
        int num=0;
        int res=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(str[i]>='0'&&str[i]<='9'){
                num = num*10+str[i]-'0';
                // cout<<num<<endl;
            }
            else if(str[i]=='+'){
                res += num*sign;
                num=0;
                sign=1;
            }
            else if(str[i]=='-'){
                res += num*sign;
                num=0;
                sign=-1;
            }
            else if(str[i]=='('){
                
                nums.push(res);
                ops.push(sign);
                res=0;
                sign=1;
            }
            else if(str[i]==')'&&nums.size()>0){
                res+=num*sign;
                num=0;
                // cout<<res<<endl;
                res = res*ops.top()+nums.top();
                ops.pop();
                nums.pop();
            }
        }
        res += sign*num;
        return res;
        
        
    }
};