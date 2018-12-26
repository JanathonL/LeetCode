52. N-Queens II
class Solution {
public:
    int totalNQueens(int n) {
        cnt=0;
        vector<int> C(n,-1);
        dfs(C,0,n);
        return cnt;
    }
    void dfs(vector<int>& C, int row, int n){
        if(row==n){
            cnt++;
            return ;
        }
        for(int j =0;j<n;j++){
            if(!check(C,row,j)) continue;
            C[row]=j;
            dfs(C,row+1,n);
            C[row]=-1;
        }
    }
    bool check(vector<int>& C, int row, int col){
        for(int i=0;i<row;i++){
            if(C[i]==col) return false;
            if(abs(i-row)==abs(C[i]-col)) return false;
        }
        return true;
    }
private:
    int cnt;
};