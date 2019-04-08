120. Triangle
// refined
// beat 64%
// time: O(N)
// space: O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(int i=0;i<triangle.size();i++){
            dp.push_back(triangle[i]);
        }
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

// refined
// beat 64%
// time: O(N)
// space: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};