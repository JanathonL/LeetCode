703. Kth Largest Element in a Stream
// refined
// time: O(Nlogk)
// space: O(k)
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> rm;
        if(k<pq.size()){
            pq.pop(); 
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */