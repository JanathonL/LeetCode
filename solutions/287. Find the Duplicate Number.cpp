// 287. Find the Duplicate Number
// （1）	Time: nlogn二分搜索，因为题目给定了范围，我们只需要按照范围搜索，从[1,n]进行搜索，每次选取mid，统计整个数组里小于mid的元素个数，
// 如果cnt>mid，那么说明这个值在[left,mid]之间，如果cnt<=mid,说明这个值在[mid+1,right]之间
// （2）	参考Linked List Cycle II 的思路，用快慢指针进行遍历直到他们相遇。
// 之后再用一个指针和慢指针一起走，直到相遇，相遇的点就是循环开始的起点，直接输出就好了。
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