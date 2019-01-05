55. Jump Game
class Solution {
public:
    bool canJump(const vector<int>& nums) {
        int reach = 1;
        for(int i =0;i<reach&& reach<nums.size();i++){
            reach = max(reach,i+1+nums[i]);
        }
        return reach>=nums.size()? true:false;
    }
};

// refined:
// beat 64.45%
// time: O(N)
// space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        int left = 0;
        int right = 0;
        while(left<=right){
            int oldright = right;
            for(int i=left;i<=oldright;i++){
                right = max(right, i+nums[i]);
                if(right>=nums.size()-1){
                    return true;
                }
            }
            left = oldright+1;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size()<=1) return true;
//         for(int i =nums.size()-1;i>=0;){
//             if(nums[i]==0){
//                 int j;
//                 int flag = 0;
//                 for(j =i;j>=0;j--){
//                     if(nums[j]>i-j || i==nums.size()-1 && nums[j]==i-j){
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     i = j;
//                 }
//                 else{
//                     return false;
//                 }
                
//             }
//             i--;
//         }
//         return true;
//     }
// };