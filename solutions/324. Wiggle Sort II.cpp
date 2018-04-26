// 324. Wiggle Sort II
class Solution {  
public:  
    void wiggleSort(vector<int>& nums) {  
        if(nums.size()<=1) return;  
        sort(nums.begin(), nums.end());  
        int len = nums.size(), k = 1, high = (len%2)?len-1:len-2, mid=nums[len/2];  
        vector<int> ans(len, mid);  
        for(int i = len-1; i >=0 && nums[i]>mid; i--, k+=2)  
            ans[k] = nums[i];  
        for(int i = 0; i < len && nums[i]<mid; i++, high-=2)  
            ans[high] = nums[i];  
        nums = ans;  
    }  
};  