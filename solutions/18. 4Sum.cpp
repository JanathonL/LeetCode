18. 4Sum
// refined
// beat 38%
// time: O(N^3)
// space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j = i+1;j<nums.size()-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k = j+1;
                int e = nums.size()-1;
                
                while(k<e){
                    // cout<<"i:"<<nums[i]<<" j:"<<nums[j]<<" k:"<<nums[k]<<" e:"<<nums[e]<<endl;
                    int tmp = nums[i]+nums[j]+nums[k]+nums[e];
                    if(tmp < target){
                        k++;
                        while(nums[k]==nums[k-1]&&k<e ) k++;
                    }
                    else if(tmp>target){
                        e--;
                        while(nums[e]==nums[e+1]&& k<e ) e--;
                    }
                    else{
                        result.push_back({nums[i],nums[j],nums[k],nums[e]});
                        k++;
                        e--;
                        while(nums[k]==nums[k-1]&&k<e ) k++;
                        while(nums[e]==nums[e+1]&&k<e ) e--;
                    }
                }
            }
        }
        return result;
    }
};