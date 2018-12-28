16. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = 0;
        int diff = 1e5;
        int mindiff = 1e5;
        for(int i =0;i<nums.size()-2;i++){
            int j = i + 1;
            int k = nums.size()-1;
            while(j<k){
                diff = abs(nums[i]+nums[j]+nums[k]-target);
                if(diff<mindiff){
                    result = nums[i]+nums[j]+nums[k];
                    mindiff = diff;
                }
                if(target>nums[i]+nums[j]+nums[k]){
                    j++;
                }
                else{
                    k--;
                }
                if(j==k){
                    break;
                }
            } 
        }
        return result;
        
    }
};


// refined
// beat 99.96%
// time: O(N^2)
// space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = 0, diff = 1e5, mindiff = 1e5;
        for(int i =0;i<nums.size()-2;i++){
            int j = i + 1;
            int k = nums.size()-1;
            while(j<k){
                int cur = nums[i]+nums[j]+nums[k];
                diff = abs(cur-target);
                if(diff<mindiff){
                    result = cur;
                    mindiff = diff;
                }
                if(target>cur){
                    j++;
                } else if(target<cur){
                    k--;
                } else {
                    return target;
                }
            } 
        }
        return result;
    }
};