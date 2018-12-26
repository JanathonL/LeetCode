// 128. Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxcnt = 0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()) continue;
            if(m.find(nums[i]-1)!=m.end()&&m.find(nums[i]+1)!=m.end()){
                int dist1 = m[nums[i]-1];
                int dist2 = m[nums[i]+1];
                m[nums[i]-1-dist1+1] = dist1 + dist2 +1;
                m[nums[i]+1+dist2-1] = dist1 + dist2 +1;
                m[nums[i]] = dist1+dist2+1;
            }
            else if(m.find(nums[i]-1)!=m.end()){
                int dist1 = m[nums[i]-1];
                m[nums[i]-1-dist1+1] = dist1 +1;
                m[nums[i]] = dist1+1;
            }
            else if(m.find(nums[i]+1)!=m.end()){
                int dist2 = m[nums[i]+1];
                m[nums[i]+1+dist2-1] = dist2 +1;
                m[nums[i]] = dist2+1;
            }
            else{
                m[nums[i]] = 1;
            }
            // cout<<nums[i]<<" "<<m[nums[i]]<<endl;
            maxcnt = max(maxcnt, m[nums[i]]);
        }
        return maxcnt;
    }
};