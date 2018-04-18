// 162-Find Peak Element
// （1） Time: O(N) 直接扫一遍，如果碰到符合条件的就返回
// （2） Time: O(logN) 二分做
// 一共四种情况
// 1）  left<mid>right  return mid
// 2）  left< mid < right 去[right+1, n]找
// 3）  left> mid > right 去[0, right]找
// 4）  left> mid <right 两边都有peak

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while(left<right){
            int mid = (left+right)/2;
            int lefth=0;
            if(mid-1>=0&&nums[mid]>nums[mid-1]||mid==0){
                lefth=1;
            }
            int righth=0;
            if(mid+1<nums.size()&&nums[mid]>nums[mid+1]||mid==nums.size()-1){
                righth = 1;
            }
            if(1==lefth&&1==righth){
                return mid;
            }
            else if(lefth) left = mid+1;
            else right = mid;
        }
    }
};
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int higher=1;
//         for(int i=0;i<nums.size()-1;i++){
//             if(i==0){
//                 higher = 1;
//             }
//             else{
//                 higher = nums[i-1]<nums[i];
//             }
//             if(nums[i]>nums[i+1]){
//                 if(higher){
//                     return i;
//                 }
//             }
//         }
//         if(higher) return nums.size()-1;
//         return 0; //only one element
//     }
// };