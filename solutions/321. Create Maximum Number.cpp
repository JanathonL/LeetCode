// 321. Create Maximum Number
// 先把这个问题分成三步来思考
// （1）	首先从一个数组里选出k个数，组成最大的数的情况
// 这时候只需要用一个stack，记录当前最大的数
// 首先先记录一下当前还是drop的数的个数 一开始 drop=n-k;
// 当前nums[i]>stack.top() 那么stack.pop()，直到stack为空或者不能drop数了，那就nums[i] push进去。
// 最后返回就好了
// （2）	然后想象一下有两个数组，然后k=m+n从这两个数组里我选取所有的数字进行操作，我只需要比一比这两个数组中哪个数字大，选哪个就好了
// 但是如果两个数字相同的情况下，那么就是要顺序比下去，直到比到某一个结束了，或者某一个数字比比较大，那么才能确定选哪个
// [1,2,3]
// [1,2,4]  那么就选下面这个数字1。
// （3）	把原来两个数组分割一下，有i个数字在数组1中，有k-i个在数组2中,然后调用之前两步写的函数。
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