689. Maximum Sum of 3 Non-Overlapping Subarrays
class Solution {
public:
    /*
    time:O(N)
    space: O(N)
    */
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res(3,0);
        if(nums.size()<3*k){  // 注意这个 size需要>= 3*k
            return res;
        }
        // from i to i+k-1
        vector<int> window(nums.size()-k+1,0);  // window表示i到i+k-1的sum是
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(i>=k) sum -= nums[i-k];
            if(i>=k-1) window[i-k+1] = sum;  
        }
        vector<int> left(window.size(),0);
        left[0] = 0;               // left是index, 左边最大的window的index
        int best = window[0];      // 初始化时window[0]
        for(int i=1;i<window.size();i++){
            if(best<window[i]) {   // 注意这里需要满足最小index，所以等于的时候不用更新
                left[i] = i;
                best = window[i];
            } else {
                left[i] = left[i-1];
            }
        }
        vector<int> right(window.size(),0);
        int n = window.size();
        right[n-1] = n-1;     // right是index， 右边最大的window的index
        best = window[n-1];   // 初始化时 window[n-1]
        for(int i=n-2;i>=0;i--){
            // make sure lexicographically order
            if(best <= window[i]) {   //注意这里需要满足最小index，所以等于的时候也要更新
                right[i] = i;
                best = window[i];
            } else {
                right[i] = right[i+1];
            }
        }
        int max_sum = INT_MIN;
        for(int j=0;j<nums.size();j++){
            if(j-k>=0 && j+2*k-1<nums.size()){ 
                int sum = window[left[j-k]];  // 最大j-k, j-k-1 ， from 0, j-k的window
                sum += window[right[j+k]];  // 最小j+k, j+2k-1， from j+k，n-k的window
                sum += window[j]; // j, j+k-1
                if(sum>max_sum){ // 这里也是保证顺序小，只有sum > max_sum才更新
                    res = {left[j-k],j,right[j+k]};
                    max_sum = sum;
                }
            }
        }
        return res;
        
    }
};