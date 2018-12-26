611. Valid Triangle Number
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size()-2;i++){
            int first = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left<nums.size()){
                while(left<right){
                    if(first+nums[left]<=nums[right]){
                        right --;
                    }
                    else{
                        sum+=right-left;
                        left++;
                        right=nums.size()-1;
                    }
                }
                left++;
                right=nums.size()-1;
            }
        }
        return sum;
    }
};