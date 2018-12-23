227. Basic Calculator II
class Solution {
public:
    /*
    prev_num = prev_num prev_op[x/-+] num
    prev_op
    if op == '+' or '-' or reach end
        res += prev_num
    15 min
    1 wrong
    time: O(N)
    space: O(1)
    */
    bool is_digit(char c){
        if(c>='0'&&c<='9'){
            return true;
        } else {
            return false;
        }
    }
    void update(int& prev_num, char prev_op, int num){
        switch(prev_op){
            case '+': prev_num += num;
                return;
            case '*': prev_num *= num;
                return;
            case '/': prev_num /= num;  // assume num != 0
                return;
            case '-': prev_num -= num;
                return;
        }
    }
    int calculate(string s) {
        int prev_num = 0;
        char prev_op = '+';
        int num = 0;
        char op;
        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            } else if(is_digit(s[i])){
                num = num*10 + s[i]-'0';
            } else {
                // update prev_num
                op = s[i];
                update(prev_num, prev_op, num);
                if(op=='+'||op=='-'){
                    res += prev_num;
                    prev_num = 0;
                }
                num = 0;
                prev_op = op;
            }
        }
        update(prev_num, prev_op, num);  // 别忘了这里更新一下
        res += prev_num;
        
        return res;
    }
    /*
    stack<int> nums;
    stack<char> ops;
    find a number put it into nums
    find a op
        check precedence of op and ops.top()
        if pre(op)<=pre(ops.top()), cal
        else ops.push(op)
    while(!op.empty()){
        cal
    }
    18 min
    2 wrong
    time: O(N)
    space: O(N)
    */
    // int cal(int first, int second, char op){
    //     switch(op){
    //         case '+':
    //             return first+second;
    //         case '-':
    //             return first-second;
    //         case '/':
    //             return first/second;  // assume second is not 0
    //         case '*':
    //             return first*second;
    //     }
    // }
    // void operation(stack<int>& nums, stack<char>& ops){
    //     int second = nums.top();
    //     nums.pop();
    //     int first = nums.top();
    //     nums.pop();
    //     char op = ops.top();
    //     ops.pop();
    //     // cout<<"f:"<<first<<" s:"<<second<<endl;
    //     cout<<cal(first, second, op)<<endl;
    //     nums.push(cal(first, second, op));
    // }
    // bool is_digit(char c){
    //     if(c>='0'&&c<='9'){
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
    // bool precedence(char op, char top){
    //     if(op=='+'||op=='-'||top=='*'||top=='/'){
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
    // int calculate(string s) {
    //     stack<int> nums;
    //     stack<char> ops;
    //     int n = s.size();
    //     int num = 0;
    //     for(int i=0;i<n;i++){
    //         if(s[i]==' '){
    //             continue;
    //         } else if(is_digit(s[i])){
    //             num = num*10+s[i]-'0';  // 注意这个地方需要 num = num*10 + s[i]-'0';
    //         } else {
    //             nums.push(num);
    //             char op = s[i];
    //             while(!ops.empty()&&precedence(op, ops.top())){
    //                 operation(nums, ops);
    //             }
    //             ops.push(op);
    //             num = 0;  // 把num变成 0
    //         }
    //     }
    //     nums.push(num);
    //     while(!ops.empty()){
    //         operation(nums, ops);
    //     }
    //     return nums.top();
    // }
};