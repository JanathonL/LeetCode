287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[nums[fast]];
            // cout<<slow<<" "<<fast<<endl;
        }
        fast=0;
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int left= 0;
//         int right = n-1;
//         while(left<right){
//             int mid = (left/2+right/2);
//             int cnt=0;
//             for(int i=0;i<n;i++){
//                 if(nums[i]<=mid){
//                     cnt++;
//                 }
//             }
//             if(cnt>mid){
//                 right=mid;
//             }
//             else{
//                 left=mid+1;
//             }
//         }
//         return right;
//     }
// };