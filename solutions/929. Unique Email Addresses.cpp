929. Unique Email Addresses
// refined beat 54%
// time: O(N)
// space: O(N)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> cache;
        for(int i=0;i<emails.size();i++){
            string email = emails[i];
            int pos = email.find('@');
            string local = email.substr(0, pos);
            string domain = email.substr(pos+1);
            local = process(local);
            cache.insert(local+"@"+domain);
        }
        return cache.size();
    }
    string process(string str){
        string res;
        for(int i=0;i<str.size();i++){
            if(str[i]=='.') continue;
            else if(str[i]=='+') break;
            else res += str[i];
        }
        return res;
    }
};