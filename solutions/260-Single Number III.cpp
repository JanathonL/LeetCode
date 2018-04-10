// 260. Single Number III
// 本题是有两个未知数，是 "Single Number" 这道题的扩展，直接做异或肯定是不行的。
// 有没有办法把两个未知数分开，使得可以应用Single Number 的解法呢？
// 设x, y是那两个未知数，那么如果对这个数组做异或的话，结果实质上等于x ^ y，因为其他数都出现了两次，被抵消了。
// 但是仅仅是通过最后异或出来的值，是没办法区分出x和y的，但是足以帮助我们把x和y划分到不停地子数组中去。
// 对于x和y，由于二者不相等，那么二者至少存在一位不相同，
// 当找到这个k以后，就可以按照第k位是否等于1，将nums数组划分为两个子数组，
// 然后把Single Number的算法直接应用到两个子数组上，就可以求出x和y了。
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(int i=0;i<nums.size();i++){
            diff ^= nums[i];
        }
        diff &= -diff;
        vector<int> res(2,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]&diff){
                res[0]^=nums[i];
            }
            else{
                res[1]^=nums[i];
            }
        }
        return res;
    }
};