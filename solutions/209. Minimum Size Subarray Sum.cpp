209. Minimum Size Subarray Sum
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