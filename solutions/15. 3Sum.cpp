class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int ptr1 = 0;
        int low = 0;
        int high = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            ptr1 = i;
            low = i+1;
            high = nums.size()-1;
            while(low<high){
                
                int sum = nums[ptr1]+nums[low]+nums[high];
                if(sum>0){
                    high--;
                } else if(sum<0){
                    low++;
                } else {
                    res.push_back({nums[ptr1], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[high]==nums[high+1]) high--;
                    while(low<high && nums[low]==nums[low-1]) low++;
                }
            }
        }
        return res;
    }
};