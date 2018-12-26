394. Decode String
class Solution {
public:
    bool is_digit(char c){
        if(c>='0'&&c<='9'){
            return true;
        } else {
            return false;
        }
    }
    string decodeString(string s) {
        if(s.size()==0){
            return "";
        }
        string res;
        int num = 0;
        for(int i=0;i<s.size();i++){
            if(is_digit(s[i])){
                num = num*10 + s[i]-'0';
            } else if(s[i]=='[') {
                int left = 0;
                int index = i;
                for(index = i;index<s.size();index++){
                    if(s[index]=='['){
                        left++;
                    } else if(s[index]==']') {
                        left--;
                        if(left==0){
                            break;
                        }
                    }
                }
                
                // cout<<s[i]<<" "<<index<<" "<<s[index]<<endl;
                int pos = index;
                string temp = decodeString(s.substr(i+1, pos-i-1));
                i = pos;
                // cout<<index<<
                for(int j=0;j<num;j++){
                    res += temp;
                }
                num = 0;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};