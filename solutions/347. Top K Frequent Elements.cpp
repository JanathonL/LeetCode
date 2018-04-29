// 347. Top K Frequent Elements
// （1） nlogn 先用一个hashmap把所有数字以及出现的次数都存下来，然后用一个vector<pair<int,int>> anslist存起来，然后排序，之后把前k个输出
// （2） O(n) 先用一个hashmap把所有数字以及出现的次数都存下来，然后用一个list以出现次数为下标（注意这时候下标最大值要写成nums.size()+1）,
// 然后对应位置就是一个vector，里面存了出现次数相同的值，最后反向遍历一下。

class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        else{
            return a.first>b.first;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }
        vector<vector<int>> anslist(nums.size()+1,vector<int>());
        for(auto item:m){
            anslist[item.second].push_back(item.first);
        }
        vector<int> res;
        for(int i=nums.size();i>=0;i--){
            if(anslist[i].size()==0) continue;
            for(auto item:anslist[i]){
                if(res.size()<k){
                    res.push_back(item);
                }
            }
            
        }
        return res;
        
    }
};
// class Solution {
// public:
//     static bool cmp(pair<int,int> a,pair<int,int> b){
//         if(a.second!=b.second){
//             return a.second>b.second;
//         }
//         else{
//             return a.first>b.first;
//         }
//     }
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++){
//             if(m.find(nums[i])!=m.end()){
//                 m[nums[i]]++;
//             }
//             else{
//                 m[nums[i]]=1;
//             }
//         }
//         vector<pair<int,int>> ans;
//         for(auto item:m){
//             ans.push_back(make_pair(item.first,item.second));
//         }
        
//         sort(ans.begin(),ans.end(),cmp);
//         vector<int> res;
//         for(int i=0;i<k;i++){
//             res.push_back(ans[i].first);
//         }
//         return res;
        
//     }
// };