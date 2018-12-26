442. Find All Duplicates in an Array
class Solution {
public:
    
    /*
    7 min
    2 wrong
    time: O(N)
    space: O(1)
    */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        // check empty
        if(nums.size()==0){
            return res;
        }
        // mark nums[index] = -nums[index]
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]) - 1 ;   // abs(num[i]) - 1
            if(nums[index]<0){
                nums[index] = -nums[index];
                res.push_back(index+1);     // 注意res是要index+1
            } else {
                nums[index] = -nums[index];
            }
        }
        return res;
        
    }
};