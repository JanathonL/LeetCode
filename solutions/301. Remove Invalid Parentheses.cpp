// 301. Remove Invalid Parentheses
// DFS
// （1） 先计算出’(‘ ‘)’ 括号多余的数量
// （2） 然后进行dfs
// 如果每次都进行判断
// if 左边括号还有多余的，那就删除左边括号  
// 或者加入左边括号到path中，然后记录现在左边括号未匹配的个数，pair+1.
// if 后边括号还有多余的，那就删除右边括号
// 或者加入右边括号到path中，然后pair-1
// 一旦 左右括号都没有多余的，pair又是0，就保存路径。
//     BFS
// （1） 把当前的字符串去掉一个’(‘或者 ‘)’的子串全部计算出来，判断是否合理，合理就结束
// （2） 否则加到队列中去，重复操作
// （3） 注意如果找到了之后，就把当前层遍历完就好了，后面的层就不要添加了。

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int lremove,rremove;
        lremove=rremove=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lremove++;
            }
            else if(s[i]==')'){
                if(lremove>0){
                    lremove--;
                }
                else{
                    rremove++;
                }
            }
        }
        unordered_set<string> res;
        dfs(s,0,lremove,rremove,0,"",res);
        vector<string> ans;
        for(auto item:res){
            ans.push_back(item);
        }
        return ans;
    }
    void dfs(string s, int index, int lremove, int rremove, int pair, string path, unordered_set<string>& res){
        if(index==s.size()){
            if(lremove==0&&rremove==0&&pair==0){
                res.insert(path);
            }
            return ;
        }
        if(s[index]!='('&&s[index]!=')'){
            dfs(s,index+1,lremove,rremove,pair,path+s[index],res);
        }
        else{
            if(s[index]=='('){
                if(lremove>0){
                    dfs(s,index+1,lremove-1,rremove,pair,path,res);
                }
                dfs(s,index+1,lremove,rremove,pair+1,path+s[index],res);
            }
            else{
                if(rremove>0){
                    dfs(s,index+1,lremove,rremove-1,pair,path,res);
                }
                if(pair>0){
                    dfs(s,index+1,lremove,rremove,pair-1,path+s[index],res);
                }
            }
        }
    }
};