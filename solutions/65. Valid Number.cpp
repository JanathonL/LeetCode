/*
trim the string
if first c is +- or num, continue
else false
if c == '.' && seen_num && !seen_p && !seen_e
    seen_p = true
else false
if c is digit
    seen_num = true
    seen_num_after_e = true
if c is e && !seen_e && seen_num
    seen_e = true
    seen_num_after_e = false
else false
return seen_num && seen_num_after e

24 min
3 wrongs
time: O(N)
space: O(1)
*/
// refined
class Solution {
public:
    void trim(string& str){
        str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
        str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
    }
    bool is_digit(char c){
        if(c>='0'&&c<='9'){
            return true;
        } else {
            return false;
        }
    }
    bool isNumber(string s) {
        bool seen_num = false;
        bool seen_e = false;
        bool seen_p = false;
        bool seen_num_after_e = true;
        trim(s);
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(i==0){
                if((c=='+'||c=='-')){
                    continue;
                } else if(is_digit(c)){
                    seen_num = true;
                    continue;
                } else if(c=='.'){
                    seen_p = true;
                    continue;
                } else {
                    return false;
                }
            } else {
                if(c=='.'&&!seen_p&&!seen_e){
                    seen_p = true;
                } else if(is_digit(c)){
                    seen_num = true;
                    seen_num_after_e = true;
                } else if(c=='e'&&!seen_e&&seen_num){
                    seen_e = true;
                    seen_num_after_e = false;
                } else if((c=='+'||c=='-')&&s[i-1]=='e'){
                    continue;
                } else {
                    return false;
                }
            }
        }
        return seen_num&&seen_num_after_e;
    }
};