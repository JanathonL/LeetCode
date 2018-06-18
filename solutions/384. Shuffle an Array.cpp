// 384. Shuffle an Array
// 建立两个数组 original，res
// shuffle的算法从i,len-1选一个与第i个元素交换。
class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        res = original;
        int len = original.size();
        for(int i=0;i<len;i++){
            int j = i+ (int)(rand()%(len-i));
            swap(res[i],res[j]);
        }
        
        return res;
    }
private:
    vector<int> original,res;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
