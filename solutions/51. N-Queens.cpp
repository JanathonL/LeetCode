51. N-Queens
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> C(n,-1);
        dfs(result,C,0,n);
        return result;
        
    }
    void dfs(vector<vector<string>>& result,vector<int> C, int cnt, int n){
        if(cnt==n){
            string s = "";
            vector<string> path;
            for(int j =0;j<n;j++){
                s+='.';
            }
            for(int i=0;i<n;i++){
                s[C[i]]='Q';
                path.push_back(s);
                s[C[i]]='.';
            }
            if(find(result.begin(),result.end(),path)==result.end())
                result.push_back(path);
            return;
        }
        for(int j=0;j<n;j++){
            if(!check(C,cnt,j)) continue;
            C[cnt]=j;
            dfs(result,C,cnt+1,n);
            C[cnt]=-1;
        }

    }
    bool check(vector<int>& C, int row, int col){
        //只检查之前的行
        for(int i =0;i<row;i++){
            // 同一列
            if(C[i]==col) return false;
            // 对角线
            if(abs(i-row)==abs(C[i]-col)) return false;
        }
        return true;
    }
    void print(vector<string> path){
        for(int i =0;i<path.size();i++){
            cout<<path[i]<<endl;
        }
        cout<<endl;
    }
};