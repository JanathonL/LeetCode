375. Guess Number Higher or Lower II
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n+1,vector<int>(n+1,0));
        //f(a,b) = min( max(f[a][k-1], f[k+1][b])+k);
        for(int i=1;i<n;i++){
            f[i][i+1]=i;
        }
        for(int i=n-2;i>=1;i--){
            for(int j=i+2;j<n+1;j++){
                int tmp=INT_MAX;
                for(int k=i+1;k<j;k++){
                    tmp = min(tmp, max(f[i][k-1],f[k+1][j])+k);
                }
                f[i][j]=tmp;
            }
        }
        return f[1][n];
        
    }
};