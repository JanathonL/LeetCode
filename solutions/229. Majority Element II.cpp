// 229. Majority Element II
// 投票计数法
// 两个计数器两个候选数
// 注意一定要先判断是否候选数相等，然后再判断是否计数器为0，最后就是c1--, c2--。
// 结束之后判断一下这两个候选数是否符合要求。

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1,c2,ca1,ca2;
        c1=c2=0;
        ca1=ca2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ca1){
                c1++;
            }
            else if(nums[i]==ca2){
                c2++;
            }
            else if(c1==0){
                ca1=nums[i];
                c1=1;
            }
            else if(c2==0){
                ca2=nums[i];
                c2=1;
            }
            else{
                c2-=1;
                c1-=1;
            }
        }
        c1 = c2 = 0;
        for(auto n: nums){
            if (n==ca1)   c1++;
            else if (n==ca2)  c2++;
        }

        vector<int> res;
        if (c1 > nums.size()/3)   res.push_back(ca1);
        if (c2 > nums.size()/3)   res.push_back(ca2);
        return res;
    }
};