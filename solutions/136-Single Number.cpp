// 136. Single Number
// 异或做只要是偶数次都可以清零
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        return x;
    }
};
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i = 0;i<nums.size()-1;i+=2){
//             if(nums[i]!=nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return nums[nums.size()-1];
//     }
// };