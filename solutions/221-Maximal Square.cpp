// 221-Maximal Square
// 可以用DP做：
// f[i][j] 表示包括点（i,j）最大能组成最大的正方形的边长
// f[i][j]=m[i][j] if i==0||j==0
// f[i][j]=min([i][j-1],[i-1][j],[i-1][j-1])+1   if m[i][j]==1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(0==n) return 0;
        int m = matrix[0].size();
        vector<vector<int>> f(n,vector<int>(m,0));
        int maxa=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    f[i][j]=matrix[i][j]-'0';
                }
                else if(matrix[i][j]-'0'==1){
                    f[i][j]=min(f[i][j-1],min(f[i-1][j],f[i-1][j-1]))+1;
                }
                // cout<<"i:"<<i<<" j:"<<j<<" f[i][j]:"<<f[i][j]<<endl;
                maxa=max(maxa,f[i][j]);
            }
        }
        return maxa*maxa;
        
        
        
    }
};