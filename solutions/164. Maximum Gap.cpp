164. Maximum Gap
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int n = nums.size();
        int mmax = INT_MIN;
        int mmin= INT_MAX;
        for(int i =0;i<nums.size();i++){
            mmax = max(nums[i],mmax);
            mmin = min(nums[i],mmin);
        }
        int len = (mmax-mmin)/(n) +1;
        // cout<<"test1"<<endl;
        vector<vector<int>> bucket((mmax-mmin)/len +1);
        for(int i =0;i<bucket.size();i++){
            // bucket.reserve(2);
            bucket[i].push_back(INT_MAX);
            bucket[i].push_back(INT_MIN);
        }
        // cout<<"test"<<endl;
        for(int i =0;i<nums.size();i++){
            int l = (nums[i]-mmin)/len;
            if(nums[i]<bucket[l][0]) bucket[l][0]=nums[i];
            if(nums[i]>bucket[l][1]) bucket[l][1]=nums[i];
        }
        
        int gap=0;
        int pre=-1;
        for(int i =0;i<bucket.size();i++){
            if(bucket[i][0]==INT_MAX||bucket[i][1]==INT_MIN) continue;
            if(pre==-1){
                pre = i;
            }
            else{
                gap=max(bucket[i][0]-bucket[pre][1],gap);
            }
            pre = i;
        }
        return gap;
    }
};