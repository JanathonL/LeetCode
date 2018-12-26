90. Subsets II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        int n = nums.size();
        map< vector<int> ,int> m;
        for(int i=0;i<1<<n;i++){
            for(int j=0;j<n;j++){
                if(i& 1<<j) {
                    path.push_back(nums[j]);
                }
            }
            sort(path.begin(),path.end());
            if(m.find(path)==m.end()){
                m[path]=0;
                result.push_back(path);
            }
            
            
            path.clear();
        }
        return result;
    }
};