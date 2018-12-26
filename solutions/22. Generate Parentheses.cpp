22. Generate Parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n,n,res,"");
        return res;
    }
    void dfs(int left, int right, vector<string>& res, string str){
        if(left==right && left==0){
            res.push_back(str);
        }
        if(left>0){
            dfs(left-1,right,res, str+'(');
        }
        if(left<right){
            dfs(left,right-1,res,str+')');
        }
    }
};