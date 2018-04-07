// 53. Maximum Subarray
// (1)	直接online做，如果遇到当前累加的sum<0就重置sum=0,时刻更新maxsum就可以了。 Time: O(n),  Space: O(1)
// (2)	DP的思想，f[i]是以nums[i]结尾最大子串的值。Time: O(n),  Space: O(1)
// 转移方程是：   
// f[j] = max(f[j-1] + s[j] , s[j]),  1<= j <= n

// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i-1]>=0){
                nums[i]=nums[i-1]+nums[i];
            }
            maxsum = max(maxsum,nums[i]);
        }
        return maxsum;
    }
};
// (1)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxsum = INT_MIN;
//         for(int i =0;i<nums.size();i++){
//             sum+=nums[i];
//             maxsum = max(maxsum,sum);
//             if(sum<0){
//                 sum=0;
//             }
//         }
//         return maxsum;
//     }
// };
