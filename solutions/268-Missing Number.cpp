// 268. Missing Number
// （1）	异或, res先与0…n异或一下，然后再与nums[0]…nums[n]异或一下，之后剩下的就是miss的
// （2）	求出sum[0…n]- sum[nums[0]…nums[n]] 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int d = 0;
        for(int i =0;i<nums.size();i++){
            d ^= nums[i];
        }
        for(int i=0;i<nums.size()+1;i++){
            d ^= i;
        }
        return d;
    }
};