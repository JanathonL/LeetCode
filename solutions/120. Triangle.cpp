120. Triangle
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