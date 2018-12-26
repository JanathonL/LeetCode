658. Find K Closest Elements
class Solution {
    bool isOk(vector<int>& nums, int k, int x, int idx) {
        return nums[idx] + nums[idx + k] >= 2 * x;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sz = arr.size(), lo = 0, hi = sz - k;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (isOk(arr, k, x, mi))
                hi = mi;
            else
                lo = mi + 1;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};