368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> f(nums.size(),0);
        vector<int> parent(nums.size(),-1);
        int mmax,mi;
        mmax = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i;j<nums.size();j++){
                if(nums[j]%nums[i]==0 && f[i]<f[j]+1){
                    f[i] = f[j]+1;
                    parent[i]=j;
                    if(f[i]>mmax){
                        mmax = f[i];
                        mi = i;
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<mmax;i++){
            res.push_back(nums[mi]);
            mi=parent[mi];
        }
        return res;
    }
};