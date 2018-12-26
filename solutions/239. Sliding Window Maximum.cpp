239. Sliding Window Maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(q.size()>0 && q.front()==i-k) q.pop_front();
            while(q.size()>0 && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
            // cout<<q.front()<<endl;
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};