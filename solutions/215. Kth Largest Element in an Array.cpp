215. Kth Largest Element in an Array
class Solution {
public:
    /*
    min heap nlogk
    4 min
    1 wrong
    */
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for(int i=0;i<nums.size();i++){
    //         pq.push(nums[i]);
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
    //     return pq.top();
    // }
    /*
    max heap klogn
    quick select
    avg O(N)
    1. Initialize left to be 0 and right to be nums.size() - 1;
    2. Partition the array, if the pivot is at the k-1-th position, return it (we are done);
    3. If the pivot is right to the k-1-th position, update right to be the left neighbor of the pivot;
    4. Else update left to be the right neighbor of the pivot.
    5. Repeat 2.
    28 min
    7 wrong
    time: O(N)  avg
    space: O(h)
    */
    int partition(vector<int>& nums, int left, int right, int k){
        int pivot = nums[left];
        int l = left + 1, r = right;
        while(l<=r){
            if(nums[r]>=pivot){
                swap(nums[l],nums[r]);
                l++;
            } else{
                r--;
            }
        }
        // cout<<r<<" "<<nums[r]<<endl;

        swap(nums[left],nums[r]);
        // for(int i=left;i<=right;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int index = partition(nums, lo, hi, k);
            // cout<<index<<endl;
            if(index==k-1){
                return nums[index];
            } else if(index>k-1){
                hi = index-1;
            } else {
                lo = index+1;
            }
        }
        return nums[lo];
    }
    
};