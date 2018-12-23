8. String to Integer (atoi)
/*
delete the leading space
check first non-space char
    if first char is sign -> continue;  -> set sign
    else if first char is non-digit and not sign -> return 0
    else 
        set sign -> +
start calculate the num
    if num > (INT_MAX-cur_digit)/10
        return sign==1? INT_MAX:INT_MIN;
reutrn sign*num;
*/
/*
"42"
pos = 3
sign = -1
num = 42
-> -42

"-2147483648"
INT_MAX = 2147483647
sign = -1
num = 214748364
cur = 8
*/
class Solution {
public:
    int myAtoi(string str) {
        // delete the leading space
        int pos = str.find_first_not_of(" ");
        
        if(pos==string::npos){
            return 0;
        }
        // check first non-space char, update pos and sign
        int sign = 1;
        int num = check(str, pos, sign);
        // invalid first char
        if(num==-1){
            return 0;
        }
        // start calculate the num
        while(pos<str.size()){
            if(is_digit(str[pos])){
                int cur_digit = str[pos]-'0';
                // overflow
                if(num>(INT_MAX-cur_digit)/10){
                    return sign==1? INT_MAX:INT_MIN;
                } else {
                    num = num*10 + cur_digit;
                }
            } else {
                break;
            }
            pos++;
        }
        return num*sign;
    }
    bool is_digit(char c){
        if(c>='0'&&c<='9'){
            return true;
        } else {
            return false;
        }
    }
    int check(string str, int& pos, int& sign){
        int num = 0;
        if(str[pos]=='+'){
            sign = 1;
        } else if(str[pos]=='-'){
            sign = -1;
        } else if(is_digit(str[pos])){
            sign = 1;
            num = str[pos] - '0';
        } else {
            // invalid
            num = -1;
        }
        pos++;
        return num;
    }
};