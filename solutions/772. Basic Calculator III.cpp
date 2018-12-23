class Solution {
public:
    /*
    prev_num = prev_num prev_op num
    prev_op
    res
    if op == '-' || op == '+'
        res += prev_num
        prev_num = 0
    num = 0
    prev_op = op
    15 min
    1 wrong
    time: O(N)
    space: O(1)
    
    */
    bool is_digit(char c){
        if(c>='0' && c<='9'){
            return true;
        } else {
            return false;
        }
    }
    bool is_op(char c){
        if(c=='*'||c=='/'||c=='-'||c=='+'){
            return true;
        } else {
            return false;
        }
    }
    void update(int& prev_num, char prev_op, int num){
        cout<<prev_num<<prev_op<<num<<endl;
        switch(prev_op){
            case '*': 
                prev_num *= num;
                return;
            case '/':
                prev_num /= num; // assume num is not zero
                return;
            case '+':
                prev_num = num;
                return;
            case '-':
                prev_num = -num;
                return;
        }
    }
    int calculate(string s){
        int prev_num = 0;
        char prev_op = '+';
        int res = 0;
        int num = 0;
        char op;
        // check empty
        if(s.size()==0){
            return 0;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue;
            } else if(s[i]=='('){
                // find right to match left
                int left = 0;
                int index = i;
                for(index = i;index<s.size();index++){
                    if(s[index]=='('){
                        left++;
                    } else if(s[index] == ')') {
                        left--;
                        if(left==0){
                            break;
                        }
                    }
                }
                num = calculate(s.substr(i+1, index-i-1));
                i = index;
            } else if(is_digit(s[i])){
                num = num*10 + s[i]-'0';
            } else if(is_op(s[i])){
                // update prev_num
                op = s[i];      // 别忘了赋值
                update(prev_num, prev_op, num);
                if(op=='+'||op=='-'){  
                    res += prev_num;
                    prev_num = 0;
                }
                num = 0;
                prev_op = op;  // 别忘了更新 prev_op 和 num
            }
        }
        // deal with last number
        update(prev_num, prev_op, num);
        res += prev_num;
        return res;
    }
    /*
    stack<int> nums
    stack<char> op
    if s[i] is digit
        update num
    else if s[i] is (
        find the matched right and calculate(s.substr(i+1,index-i-1))
        num += res
        i = index // update i
    else if s[i] == ' '
        continue
    else if s[i] is op
        while(!op.empty() && precedence(s[i], op.top()))
            operations()
        op.push(s[i])
        nums.push(num)
        num = 0
    
    while(!op.empty()){
        operations()
    }
    return num.top()
    
    26 min
    5 wrong
    time: O(N)
    space: O(N)
    
    */
//     bool is_digit(char c){
//         if(c>='0' && c<='9'){
//             return true;
//         } else {
//             return false;
//         }
//     }
//     bool is_op(char c){
//         if(c=='*'||c=='/'||c=='-'||c=='+'){
//             return true;
//         } else {
//             return false;
//         }
//     }
//     bool precedence(char first, char second){
//         if(second=='+'||second=='-' || first=='*' || first=='/'){
//             return true;
//         } else {
//             return false;
//         }
//     }
//     int cal(int first, int second, char op){
//         switch(op){
//             case '+':
//                 return first+second;
//             case '-':
//                 return first-second;
//             case '*':
//                 return first*second;
//             case '/':
//                 return first/second; // assume second is not zero
//         }
//     }
//     void operation(stack<int>& nums, stack<char>& ops){
//         int second = nums.top();
//         nums.pop();
//         int first = nums.top();
//         nums.pop();
//         char op = ops.top();
//         ops.pop();
//         int num = cal(first, second, op);
//         nums.push(num);
//     }
//     int calculate(string s) {
//         // check empty
//         if(s.size()==0){
//             return 0;
//         }
//         int num = 0;
//         stack<int> nums;
//         stack<char> ops;
//         for(int i = 0;i<s.size();i++){
//             if(s[i]==' '){
//                 continue;
//             } else if(s[i]=='('){
//                 int left = 0;
//                 int index = i;
//                 for(index=i;index<s.size();index++){
//                     if(s[index]=='('){
//                         left++;
//                     } else if(s[index]==')') {
//                         left--;
//                         if(left==0){
//                             break;
//                         }
//                     }
//                 }
//                 num += calculate(s.substr(i+1, index-i-1));
                
//                 i = index;  // I will also perform i++ in the loop to skip ')'
//             } else if(is_digit(s[i])){
//                 num = num*10 + s[i]-'0';
//             } else if(is_op(s[i])){
//                 nums.push(num);  // 注意要先push num, 在进行判断，不然的话，没有足够的操作数
//                 while(!ops.empty() && precedence(ops.top(), s[i])){
//                     operation(nums, ops);
//                 }
//                 ops.push(s[i]);
//                 num = 0;  // restore num
//             }
//         }
//         nums.push(num); // final num 一定要注意处理最后一个数字
//         while(!ops.empty()){
//             operation(nums, ops);
//         }
//         return nums.top();
//     }
};