224. Basic Calculator
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