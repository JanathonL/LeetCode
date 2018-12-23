468. Validate IP Address
class Solution {
public:
    
    /*
    Valid IPv4 and IPv8 respectively:
For IPv4:

Should be exactly 4 parts splitted by '.', and the last char cannot be '.'
The length of each part cannot be larger than 3, and if length is larger than 2, the first digit cannot be 0
Each part can only be digit, and the value should between 0 and 255
For IPv6:

Should be exactly 8 parts splitted by ':', and the last char cannot be ':'
The length of each part cannot be larger than 4
Each part can only be digit, or letter 'a'-'f', 'A'-'F'
    25 min
    3 wrong
    time: O(N)
    space: O(N)
    
    */
    bool is_digit(char c){
        if(c>='0' && c<='9'){
            return true;
        } else {
            return false;
        }
    }
    bool is_hex(char c){
        if((c>='0' && c<='9') || (c>='a' && c<='f') || (c>='A'&&c<='F')){  // hex is A to F
            return true;
        } else {
            return false;
        }
    }
    bool check_num(string str, string option){
        if(str.size()==0) {  // num can not be empty for both ipv4 and ipv6
            return false;
        }
        if(option=="ipv4"){
            for(int i=0;i<str.size();i++){
                if(is_digit(str[i])){
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            for(char c:str){
                if(is_hex(c)){
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        }
    }
    string validIPAddress(string IP) {
        // check empty
        if(IP.size()==0){
            return "Neither";
        }
        istringstream is(IP);
        if(IP.find('.')!=string::npos){
            // check IPV4
            // 3 '.', 4 nums
            // no leading zero
            // nums is range from 0 to 255
            int cnt = 0;
            string str;
            while(getline(is, str, '.')){
                // leading zero  (str[0]=='0' && str.size()>1)
                if(!check_num(str,"ipv4") || (str[0]=='0' && str.size()>1)|| str.size()>3){
                    return "Neither";
                }
                int num = stoi(str);
                
                cnt++;
                if(num>=0&&num<=255){
                    continue;
                } else {
                    return "Neither";
                }
            }
            if(cnt==4&&IP.back()!='.'){
                return "IPv4";
            } else {
                return "Neither";
            }
        } else {
            // check IPV6
            // 7 ':', 8 nums  hex upp low
            // num is <=4 digit
            int cnt = 0;
            string str;
            while(getline(is, str, ':')){
                if(!check_num(str, "ipv6") || str.size()>4 || str.size()==0){
                    return "Neither";
                } 
                cnt++;
            }
            if(cnt==8&&IP.back()!=':'){
                return "IPv6";
            } else {
                return "Neither";
            }
        }
    }
};