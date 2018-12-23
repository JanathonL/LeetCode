31. Next Permutation
/*
1 2 5 3 2
1 3 5 2 2 -> 1 3 2 2 5
找下一个
from end to begin find 1st num A (index i) < prev num
from end to begin find 1st num B (index j) > num A 
swap (A,B)
reverse from i+1 to end 
8 mins
time: O(N)
space: O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) {
            return;
        }
        int first = -1;
        int second = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                first = i;
                break;
            } 
        }
        if(first == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[first]){
                second = i;
                break;
            }
        }
        swap(nums[first],nums[second]);
        reverse(nums.begin()+first+1, nums.end());
    }
};
// 找前一个prev number
/*
from end to begin find 1st num A (index i) > prev num
from end to begin find 1st num B (index j) < num A 
swap (A,B)
reverse from i+1 to end 
*/
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         if(nums.size()<=1) {
//             return;
//         }
//         int first = -1;
//         int second = -1;
//         for(int i=nums.size()-2;i>=0;i--){
//             if(nums[i]>nums[i+1]){
//                 first = i;
//                 break;
//             } 
//         }
//         if(first == -1) {
//             reverse(nums.begin(),nums.end());
//             return;
//         }
//         for(int i=nums.size()-1;i>=0;i--){
//             if(nums[i]<nums[first]){
//                 second = i;
//                 break;
//             }
//         }
//         swap(nums[first],nums[second]);
//         reverse(nums.begin()+first+1, nums.end());
//     }
// };