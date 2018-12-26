45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int left = 0;
        int step = 0;
        int right = 0;
        while(left<=right){
            step++;
            int old_right = right;
            for(int i =left;i<=old_right;i++){
                int new_right = i+nums[i];
                if(new_right>=nums.size()-1) return step;
                if(new_right> right) right = new_right; 
            }
            left = old_right+1;
            
        }
        return 0;
    }
};