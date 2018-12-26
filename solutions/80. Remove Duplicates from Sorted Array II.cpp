80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int cnt=0;
        int index=1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[index-1]&&cnt<1){
                nums[index++]=nums[i];
                cnt++;
            }
            else if(nums[i]!=nums[index-1]){
                nums[index++]=nums[i];
                cnt = 0;
            }
        }
        return index;
    }
};