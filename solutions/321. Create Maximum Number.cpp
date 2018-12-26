321. Create Maximum Number
class Solution {
public:
    vector<int> maxk(vector<int> nums, int k){
        int n = nums.size();
        int drop = n-k;
        vector<int> s;
        for(int i=0;i<n;i++){
            while(s.size()>0&&nums[i]>s.back()&&drop>0){
                s.pop_back();
                drop--;
            }
            s.push_back(nums[i]);
        }
        s.resize(k);
        return s;
    }
    bool is_greater(vector<int> nums1,int i,vector<int> nums2,int j){
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                i++;
                j++;
            }
            else{
                return nums1[i]>nums2[j];
            }
        }
        return j==nums2.size();
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2){
        int i=0,j=0;
        vector<int> ans;
        while(i<nums1.size()&&j<nums2.size()){
            if(is_greater(nums1,i,nums2,j)) {
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j++]);
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        for(int len=0;len<=k;len++){
            if(len>nums1.size() || k-len>nums2.size()) continue;
            vector<int> max1 = maxk(nums1,len);
            vector<int> max2 = maxk(nums2,k-len);
            vector<int> tmp = merge(max1,max2);
            if(is_greater(tmp,0,result,0)) result = tmp;
        }
        return result;
        
    }
};