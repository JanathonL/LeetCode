// 152. Maximum Product Subarray
// (1)	DP: Time: O(n),  Space: O(n)
// f[i]是以nums[i]结尾最大子串的值
// g[i]是以nums[i]结尾最小子串的值
// 状态转移方程：
// f[i] = max(f[i-1]*nums[i], g[i-1]*nums[i], nums[i])
// g[i] = max(f[i-1]*nums[i],g[i-1]*nums[i], nums[i])

// 注意坑点：
// (1)  max和min的时候都要包括nums[i]本身的比较，比如g[i]或者f[i]是0的话，需要舍弃用当前值替换。
// (2)	优化上面的思路，f[i]和g[i]可以用一个值maxlocal和minlocal，这样空间可以优化到O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(nums);
        vector<int> g(nums);
        int maxsum = nums[0];
        for(int i =1;i<n;i++){
            f[i]=max(max(f[i-1]*nums[i],g[i-1]*nums[i]),nums[i]);
            g[i]=min(min(f[i-1]*nums[i],g[i-1]*nums[i]),nums[i]);
            maxsum = max(f[i],maxsum);
        }
        for(int i =0;i<n;i++){
            f[i]=nums[i];
            g[i]=nums[i];
        }
        for(int i=n-1;i>0;i--){
            f[i-1]=max(max(f[i]*nums[i-1],g[i]*nums[i-1]),nums[i-1]);
            g[i-1]=min(min(f[i]*nums[i-1],g[i]*nums[i-1]),nums[i-1]);
            maxsum = max(f[i-1],maxsum);
        }
        return maxsum;
    }
};