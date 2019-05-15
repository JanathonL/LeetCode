// 247. Strobogrammatic Number II
// Time: O(5^n)
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);
    }
    vector<string> helper(int n, int m){
        vector<string> res;
        if(n==0) {
            res.push_back("");
            return res;
        }
        else if (n==1){
            res.push_back("1");
            res.push_back("8");
            res.push_back("0");
            return res;
        }
        vector<string> lists = helper(n-2,m);
        for(int i=0;i<lists.size();i++){
            string s = lists[i];
            if(n!=m) res.push_back("0"+s+"0");
            res.push_back("1"+s+"1");
            res.push_back("6"+s+"9");
            res.push_back("9"+s+"6");
            res.push_back("8"+s+"8");
        }
        cout<<res.size()<<endl;
        return res;
    }
};

// refined time: O(5^n)

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n==1){
            return {"0","1","8"};
        }
        unordered_map<char,char> dict;
        dict['6'] = '9';
        dict['9'] = '6';
        dict['8'] = '8';
        dict['0'] = '0';
        dict['1'] = '1';
        vector<string> res;
        string cur(n, 'x');
        dfs(res, n, dict, cur, 0);
        return res;
    }
    void dfs(vector<string> &res, int n, unordered_map<char, char> &dict, string cur, int pos){
        
        if(pos >= (n+1)/2){
            res.push_back(cur);
            return;
        }
        for(auto item:dict){
            if(pos==0 && item.first == '0'){
                continue;
            } else if (pos==(n+1)/2-1 && n%2==1 && (item.first=='6' || item.first=='9')) {
                continue;
            } else {
                cur[pos] = item.first;
                cur[n-pos-1] = item.second;
                dfs(res, n, dict, cur, pos+1);
                cur[pos] = 'x';
                cur[n-pos-1] = 'x';
            } 
        }
    }
    
    
};