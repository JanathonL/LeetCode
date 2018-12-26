363. Max Sum of Rectangle No Larger Than K
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }
            
            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}
};
// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         int row = matrix.size();
//         if(row==0) return 0;
//         int col = matrix[0].size();
//         vector<vector<int>> dp(row,vector<int>(col,0));
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(i==0&&j==0){
//                     dp[i][j]=matrix[i][j];
//                 }
//                 else if(i==0){
//                     dp[i][j]=matrix[i][j]+dp[i][j-1];
//                 }
//                 else if(j==0){
//                     dp[i][j]=matrix[i][j]+dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j]=matrix[i][j]-dp[i-1][j-1]+dp[i][j-1]+dp[i-1][j];
//                 }
//             }
//         }
//         int mmax = INT_MIN;
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 for(int a=0;a<=i;a++){
//                     for(int b=0;b<=j;b++){
//                         int tmp = 0;// dp[i][j]+dp[a][b]-dp[a][j]-dp[i][b];
//                         if(a==0&&b==0){
//                             tmp = dp[i][j];
//                         }
//                         else if(a==0){
//                             tmp = dp[i][j]-dp[i][b-1];
//                         }
//                         else if(b==0){
//                             tmp = dp[i][j]-dp[a-1][j];
//                         }
//                         else{
//                             tmp = dp[i][j]+dp[a-1][b-1]-dp[a-1][j]-dp[i][b-1];
//                         }
                        
//                         if(tmp<=k)
//                             mmax = max(mmax,tmp);
                        
//                     }
//                 }
//             }
//         }
//         return mmax;
//     }
// };