//Time: O(n)  Space:O(1)
class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int num = 0;
        char pre_op = '+';
        int sum = 0,pre_sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num = num*10 + s[i]-'0';
            }
            else if(s[i]=='(')
            {
                int start = i;
                int cnt=0;
                while(1)
                {
                    if(s[i]=='(') cnt++;
                    if(s[i]==')') cnt--;
                    if(cnt==0) break;
                    i++;
                }
                string str = s.substr(start+1,i-start-1);
                num = calculate(str); // recursive
            }
            
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i==s.size()-1)
            {
                // update pre_sum    
                update_pre(pre_sum, pre_op)        
                if(s[i]=='+' || s[i]=='-' || i==s.size()-1)
                {
                    sum += pre_sum;
                    pre_sum = 0;
                }
                pre_op = s[i];
                num = 0;//清0！！！ restore num
            }
        }   
        return sum;
    }
    void update_pre(int& pre_sum, char pre_op){
        switch(pre_op)
        {
            case '+':
                pre_sum = num;
                break;
            case '-':
                pre_sum = -num;
                break;
            case '*':
                pre_sum *= num;
                break;
            case '/':
                pre_sum /= num;
                break;
        }
    }
};
// class Solution {
// public:
//     int calculate(string s) {
//         if(s.size()==0) return 0;
//         stack<int> nums;
//         stack<char> ops;
//         int num = 0;
//         for(int i=0;i<s.size();i++){
//             char c = s[i];
//             if(c==' ') continue;
//             if(c>='0' && c<='9'){
//                 num = c-'0';
//                 while(i<s.size()-1 && s[i+1]>='0' && s[i+1]<='9'){
//                     num = num*10 + (s[i+1]-'0');
//                     i++;
//                 }
//                 nums.push(num);
//                 num = 0; // reset the number to 0 before next calculation
//             } else if(c== '('){
//                 ops.push(c);
//             } else if(c == ')'){
//                 while(ops.top()!='('){
//                     operation(ops,nums);
//                 }
//                 ops.pop(); // get rid of '(' in the ops stack
//             } else if(c=='+' || c=='-' || c=='*' || c=='/'){
//                 while(!ops.empty() && precedence(c, ops.top())){
//                     operation(ops,nums);
//                 }
//                 ops.push(c);
//             }
//         }
//         while(!ops.empty()){
//             operation(ops,nums);
//         }
//         return nums.top();
//     }
//     void operation(stack<char>& ops, stack<int>& nums){
//         int first = nums.top();
//         nums.pop();
//         int second = nums.top();
//         nums.pop();
//         char op = ops.top();
//         ops.pop();
//         nums.push(cal(op, first, second));
//     }
//     int cal(char op, int b, int a) {
//         switch (op) {
//             case '+': return a + b;
//             case '-': return a - b;
//             case '*': return a * b;
//             case '/': return a / b; // assume b is not 0
//         }
//         return 0;
//     }
//     bool precedence(char op1, char op2) { // cal precedence
//         if (op2 == '(' || op2 == ')') return false;
//         if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) return false;
//         return true;
//     }
// };