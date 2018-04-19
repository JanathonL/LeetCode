// 209. Minimum Size Subarray Sum
// （1） O(N)
// 直接扫描，定义start,end, 先end向后扫描，直到sum>= target，然后start向后扫描直到sum<target， 
// 当前最短就是 minl = min(minl, end-start+1);
// （2） O(nlogn)
// 这个的思路是，先计算出 sums[]， 这个表示前k个数相加序列，这时候我只需要先找到一个sums[i]> target, 
// 然后去sums中找大于sums[i]-target的第一个sums[j],这时候算出来的距离就是 i-j+1， 
// 注意一定要大于sums[i]-target，这样更好统一情况。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int minl=INT_MAX;
        vector<int> sums = cal_sums(nums);
        for(int i=1;i<sums.size();i++){
            if(sums[i]<target) continue;
            int p = find(sums,sums[i]-target);
            minl=min(minl,i-p+1);
        }
        return minl==INT_MAX? 0:minl;
    }
    vector<int> cal_sums(vector<int> nums){
        vector<int> sums(nums.size()+1, 0);
        for(int i=1;i<nums.size()+1;i++){
            sums[i]=nums[i-1]+sums[i-1];
        }
        return sums;
    }
    int find(vector<int> sums, int target){
        int l=0, r=sums.size();
        while(l<r){
            int mid = (l+r)/2;
            if(sums[mid]>target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        if(sums[l]>target) return l;
        else return l+1;
    }
};
// O(n)
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n=nums.size();
//         if(n==0) return 0;
//         int minl=INT_MAX;
//         int s,e;
//         s=e=0;
//         int sum =0;
//         while(true){
//             while(e<n&&sum<target) sum+=nums[e++];
//             // cout<<sum<<endl;
//             if(sum<target) break;
//             while(s<e && sum>=target) sum-=nums[s++];
//             minl = min(minl,e-s+1);
//         }
//         return minl==INT_MAX? 0:minl;
//     }
// };