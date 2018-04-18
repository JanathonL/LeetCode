// 300. Longest Increasing Subsequence
// (1)	DFS: Time: O(n^2),  Space: O(1)
// 直接dfs做，注意剪枝，不然超时
// 我加了一个nums.size()- i>maxlen-cnt的剪枝，也就是如果后续数字总的长度加上当前序列长度小于maxlen，那就不要搜了。
// (2)	DP: Time: O(n^2),  Space: O(n)
// f[i]表示以nums[i]结尾的最大递增序列长度
// 状态转移方程就是
// f[j]=max(f[j],f[i]+1) if(i<j&&nums[i]<nums[j])
// (3)	二分查找，维护一个递增数组list。 Time: O(n log n),  Space: O(n)
// 如果这个数比数组里所有的元素都大，list.push_back(nums[i]), 否则 list[pos] = nums[i]更新对应位置。
// 二分维护递增数组 Time: O(n log n),  Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> l;
        for( int i =0;i<nums.size();i++){
            int pos = find(l,0,l.size(),nums[i]);
            if(pos>=l.size()){
                l.push_back(nums[i]);
            }
            else{
                l[pos]=nums[i];
            }
        }
        return l.size();
    }
    int find(vector<int> l, int low, int high, int target){
        while(low<high){
            int mid = low + (high-low)/2;  // avoid overflow!
            if(l[mid]<target){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
private:
    int maxlen;
};

// DP Time: O(n^2),  Space: O(n)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.size()==0) return 0;
//         maxlen=1;
//         vector<int> f(nums.size(),1);
//         for(int j=1;j<nums.size();j++){
//             for(int i=0;i<j;i++){
//                 if(nums[i]<nums[j]){
//                     f[j]=max(f[j],f[i]+1);
//                 }
//             }
//             maxlen=max(maxlen,f[j]);
//         }
//         return maxlen;
//     }
// private:
//     int maxlen;
// };



// DFS  Time: O(n^2),  Space: O(1)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         maxlen=0;      
//         dfs(nums,0,0,INT_MIN);
//         return maxlen;
//     }
//     void dfs(vector<int> nums, int start, int cnt, int last){
//         // cout<<"last:"<<last<<endl;
//         maxlen=max(cnt,maxlen);
//         if(start==nums.size()) {
//             return;
//         }
        
//         for(int i =start;i<nums.size();i++){
//             if(nums[i]>last&& nums.size()- i>maxlen-cnt){
//                 dfs(nums,i+1,cnt+1,nums[i]);
//             }
//         }
//     }
// private:
//     int maxlen;
// };

