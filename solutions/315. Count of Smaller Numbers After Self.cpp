315. Count of Smaller Numbers After Self
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