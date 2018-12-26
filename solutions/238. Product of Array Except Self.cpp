238. Product of Array Except Self
// class Solution {
// public:
//     /*
//     3 min
//     1 wrong
//     time: O(N)
//     space: O(1)
//     */
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> res;
//         int product = 1;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             res.push_back(product);
//             product *= nums[i];
//         }
//         product = 1;
//         for(int i=n-1;i>=0;i--){
//             res[i] *= product;
//             product *= nums[i];
//         }
//         return res;
//     }
// };
class Solution {
public:
    /*
    可以使用除法，需要对0进行特殊判断
    time: O(N)
    space: O(1)
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1, count = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) count ++;
            else sum *= nums[i];
        }
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] = nums[i] == 0 ?
                (count > 1 ? 0 : sum) :
                (count > 0 ? 0 : sum / nums[i]);
        }
        return nums;
    }
};