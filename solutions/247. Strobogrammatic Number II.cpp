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