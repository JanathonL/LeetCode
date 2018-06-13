// 376. Wiggle Subsequence
// （1）	DP思路
// p[i]表示到位置i为止，末尾差值为负的最长序列
// q[i]表示到位置i为止，末尾差值为正的最长序列
// if(nums[i]>nums[j]) q[i]=max(q[i],p[j]+1);
//     else if(nums[i]<nums[j]) p[i]=max(p[i],q[j]+1);
// （2）	贪婪算法
// 只选递增或者递减序列的最后一个元素，这样可以让后面的数有最大的递减或者递增空间，可以写一个算法，只记录前后相减flag翻转变换的次数
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> p(n,1);
        vector<int> q(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) q[i]=max(q[i],p[j]+1);
                else if(nums[i]<nums[j]) p[i]=max(p[i],q[j]+1);
            }
        }
        return max(q[n-1],p[n-1]);
    }
};