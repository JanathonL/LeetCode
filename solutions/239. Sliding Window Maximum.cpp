// 239. Sliding Window Maximum
// 使用一个deque记录当前窗口内的最大值的index，从大到小存储，如果新来一个nums[i]比q.back()大就pop_back()，直到有一个数比nums[i]大或者整个数组为空。
// 当q.front()+k==i时说明这个数要被舍弃了，pop_front().

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