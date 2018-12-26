560. Subarray Sum Equals K
class Solution {
public:
    /*
    [1,1,1]
    k = 2
    pre_sum: 0:1, 1:1, 2:1, 3:1
    sum = 3
    res = 2
    return 2
    8 min 
    bug free
    time: O(N)
    space: O(N)
    */
    int subarraySum(vector<int>& nums, int k) {
        // check empty
        if(nums.size()==0){
            return 0;
        }
        unordered_map<int, int> pre_sum;
        pre_sum[0] = 1;
        int sum = 0;
        int res = 0;
        // compute prefix sum
        for(int n:nums){
            sum += n;
            if(pre_sum.count(sum-k)){
                res += pre_sum[sum-k];
            }
            pre_sum[sum]++;
        }
        return res;
    }
};