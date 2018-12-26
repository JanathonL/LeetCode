85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> height(n,vector<int>(m,0));
        // for(int i =0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[i][j]= i==0? 1: height[i-1][j]+1;
                }
                else{
                    height[i][j]=0;
                }
                // cout<<height[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        int maxh = INT_MIN;
        for(int i=0;i<n;i++){
            maxh = max(maxh,maxhist(height[i]));
        }
        return maxh;
    }
    int maxhist(vector<int> height){
        stack<int> s;
        height.push_back(0);
        int i =0;
        int maxh = 0;
        while(i<height.size()){
            if(s.empty()||height[i]>=height[s.top()]){
                s.push(i++);
            }
            else{
                int t = s.top();
                s.pop();
                maxh=max(maxh, height[t]* (s.empty()? i : i-s.top()-1));
            }
        }
        return maxh;
    }
};