// 120. Triangle
// 算法：动态规划
// 设状态为f(i, j)，表示从从位置(i,j)出发，路径的最小和，则状态转移方程为
// f(i,j) = min(f(i+1,j), f(i+1,j+1)) + nums(i,j)
// Time: O(n)
// 如果新开一个数组 Space: O(n)
// 也可以直接在原数组上弄：Space: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        int n = triangle.size();
        vector<vector<int>> f;
        vector<int> last(n+1,0);
        triangle.push_back(last);
        for(int i =0;i<triangle.size();i++){
            f.push_back(triangle[i]);
        }
        for(int i =n-1;i>=0;i--){
            for(int j =0;j<triangle[i].size();j++){
                f[i][j]=min(f[i+1][j]+triangle[i][j],f[i+1][j+1]+triangle[i][j]);
            }
        }
        return f[0][0];
        
    }
};
