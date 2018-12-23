523. Continuous Subarray Sum
class Solution {
public:
    /*
    27 min
    7 wrong
    time: O(N)
    space: O(k)
    */
    // bool checkSubarraySum(vector<int>& nums, int k) {
    //     unordered_set<int> sum_mod_k;
    //     int pre = 0;
    //     int sum = 0;
    //     for(int n:nums){
    //         sum += n;
    //         int mod = k==0? sum:sum%k;
    //         if(sum_mod_k.count(mod)){
    //             return true;
    //         }
    //         sum_mod_k.insert(pre);  // 每次都先放pre
    //         pre = mod;  // 用一个pre去保证确保array size必须大于等于2
    //     }
    //     return false;
    // }
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> sum_mod_k;
        int s = 1;
        queue<int> pre_que;   // 如果要至少size是s那就用一个pre_que保存pre
        int pre = 0;
        pre_que.push(pre);
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            sum += n;
            int mod = k==0? sum:sum%k;
            if(sum_mod_k.count(mod)){
                return true;
            }
            if(i>=s-1){
                sum_mod_k.insert(pre_que.front());  // 每次都先放pre
                pre_que.pop();
            }
            pre_que.push(mod);  // 用一个pre去保证确保array size必须大于等于2
        }
        return false;
    }
};