330. Patching Array
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        sort(nums.begin(),nums.end());
        int add = 0;
        int i =0;
        while(miss<=n){
            
            if(i<nums.size()&&miss>=nums[i]){
                miss+=nums[i++];
            }
            else{
                miss+=miss;
                add++;
            }

        }
        return add;
    }
};