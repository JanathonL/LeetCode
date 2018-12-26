131. Palindrome Partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        // for(int i =1;i<=s.size();i++){
        dfs(s,path,result);

        return result;
    }
    void dfs(string str,vector<string> path,vector<vector<string>>& result){
        if(str.size()==0){
            result.push_back(path);
            return;
        }
        for(int i=1;i<=str.size();i++){
            if(valid(str.substr(0,i))){
                path.push_back(str.substr(0,i));
                dfs(str.substr(i),path,result);
                path.pop_back();
            }
        }
        
    }
    bool valid(string str){
        if(str.size()<=1) return true;
        int n = str.size();
        int mid = n/2;
        if(str.size()%2==0){
            for(int i=0;i<mid;i++){
                if(str[i]!=str[n-i-1])
                    return false;
            }
            return true;
        }
        else{
            for(int i =0;i<mid;i++){
                if(str[i]!=str[n-i-1])
                    return false;
            }
            return true;
        }
    }
};