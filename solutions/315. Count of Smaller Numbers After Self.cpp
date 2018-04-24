// 315. Count of Smaller Numbers After Self
// (1)	二分搜索
// 从末尾开始插入，维护一个递增数组，每次都找到第一个比当前这个元素小的数，存入这个数的坐标，然后插入到这个坐标上来。
// (2)	BST
// 维护一个BST，从末尾开始插入，每次都更新small这个数。
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> order;
        for(int i=nums.size()-1;i>=0;i--){
            int left=0;
            int right = order.size();
            while(left<right){
                int mid = left+ (right-left)/2;
                if(order[mid]>=nums[i]){
                    right = mid;
                }
                else{
                    left = mid+1;
                }
            }
            // cout<<right<<endl;
            res[i]=right;
            order.insert(order.begin()+right,nums[i]);
        }
        return res;
    }
};