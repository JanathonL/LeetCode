713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> const &nums, int k) {
        if (k == 0) return 0;
        if (nums.size() < 2) return !nums.empty() && nums[0] < k;
        int result = 0;
        for (int prod = 1, left = 0, right = 0; right != nums.size(); ++right) {
            prod *= nums[right];
            if (prod < k) result += right - left + 1;
            else {
                while (prod >= k && left <= right) prod /= nums[left++];
                result += right - left + 1;
            }
        }
        return result;
    }
};