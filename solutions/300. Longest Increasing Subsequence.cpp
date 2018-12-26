300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int row = nums.size();
        vector<int> dp(row, 1);
        int max_len = 1;
        for(int i=1;i<row;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(dp[i],max_len);
        }
        return max_len;
    }
    
    /*
    5 min
    1 wrong
    time: O(N^2)
    space: O(N)
    加了一个parent打印路径
    */
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.size()==0){
//             return 0;
//         }
//         int row = nums.size();
//         vector<int> dp(row, 1);
//         unordered_map<int, int> parent;
//         int max_len = 1;
//         int max_ind = 0;
//         for(int i=1;i<row;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[i]>nums[j]){
//                     if(dp[j]+1>dp[i]){
//                         parent[i] = j; 
//                         dp[i] = max(dp[i], dp[j]+1);
//                     }
//                 }
//             }
//             if(dp[i]>max_len){
//                 max_len = max(dp[i],max_len);
//                 max_ind = i;
//             }
//         }
//         print_path(parent, max_ind, nums);
//         return max_len;
//     }
//     void print_path(unordered_map<int, int>& parent, int& max_ind, vector<int> nums){
//         if(parent.count(max_ind)){
//             print_path(parent, parent[max_ind], nums);
//         }
//         cout<<nums[max_ind]<<endl;
        
//     }
};