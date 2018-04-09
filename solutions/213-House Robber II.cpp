// 213. House Robber II
// 分成两种，一种是从第一家抢到倒数第二家，另一种是从第二家抢到最后一家

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==0) return 0;
//         if(n==1) return nums[0];
//         vector<int> d(n+1,0);
//         d[0]=0;
//         d[1]=nums[0];
//         for(int i =2;i<n;i++){
//             d[i]=max(d[i-1],d[i-2]+nums[i-1]);
//         }
//         int maxm=d[n-1];
//         vector<int> d2(n+2,0);
//         d2[n+1]=0;
//         d2[n]=nums[n-1];
//         for(int i = n-1;i>=2;i--){
//             d2[i]=max(d2[i+1],d2[i+2]+nums[i-1]);
//         }
//         return max(maxm,d2[2]);
//     }
// };