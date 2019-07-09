503. Next Greater Element II
// refined 
// time: O(n)
// space: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> stk;
        for(int i=nums.size()*2-1;i>=0;i--){
            while(!stk.empty()&&nums[stk.top()]<=nums[i%nums.size()]){
                stk.pop();
            }
            if(!stk.empty()){
                res[i%nums.size()] = nums[stk.top()]; 
            } else {
                res[i%nums.size()] = -1;
            }
            stk.push(i%nums.size());
        }
        return res;
    }
};