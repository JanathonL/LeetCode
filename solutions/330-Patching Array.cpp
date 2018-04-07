// 1.	330. Patching Array
// 这题思路太棒了，定一个miss表示目前子串可以模拟到[1,miss)，
// 这时候如果nums[i]<miss那么可以通过在[1,miss)里每个数都加上nums[i]来使得模拟到[1,miss+nums[i]), 
// 如果nums[i]>miss,那最好的办法就是直接插入miss,使得模拟到[1,miss+miss),最后如果miss>target了那么就模拟结束了。
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
