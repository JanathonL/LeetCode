93. Restore IP Addresses
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> ip; // 存放中间结果
        dfs(s, ip, result, 0);
        return result;
        
    }
    void dfs(string s, vector<string>& ip, vector<string> &result,
            size_t start) {
        if (ip.size() == 4 && start == s.size()) {  // 找到一个合法解
            result.push_back(ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3]);
            return;
        }

        if (s.size() - start > (4 - ip.size()) * 3)
            return;  // 剪枝
        if (s.size() - start < (4 - ip.size()))
            return;  // 剪枝

        int num = 0;
        for (size_t i = start; i < start + 3 && i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');

            if (num < 0 || num > 255) continue;  // 剪枝

            ip.push_back(s.substr(start, i - start + 1));
            dfs(s, ip, result, i + 1);
            ip.pop_back();

            if (num == 0) break;  // 不允许前缀0，但允许单个0
        }
    }
};

// without pruning
// beat 39%
// time: O(1)
// space: O(1)
// 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        int start = 0;
        dfs(s, res, ip, 0);
        return res;
    }
    void dfs(string s, vector<string>& res, vector<string> ip, int start){
        if(ip.size()==4&&start==s.size()){
            string real_ip = ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3];
            res.push_back(real_ip);
            return;
        }
        if(ip.size()>=4) return; 
        int num = 0;
        for(int i=start;i<s.size();i++){
            num = num*10+s[i]-'0';
            if(num<0||num>255) continue;
            ip.push_back(to_string(num));
            dfs(s, res, ip, i+1);
            ip.pop_back();
            if(num==0) break;
        }
    }
};