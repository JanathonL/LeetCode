384. Shuffle an Array
class Solution {
public:
    /*
    3 min
    bug free
    time: O(N)
    space: O(N)
    */
    Solution(vector<int> nums):old(nums), nums(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = old;
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int index = rand()%(n-i) + i;
            swap(nums[i], nums[index]);
        }
        return nums;
    }
vector<int> old;
vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */