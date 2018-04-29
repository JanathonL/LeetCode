// 349. Intersection of Two Arrays
// O(n) 用hashmap记录一下有哪些值，然后第二个数组遍历一下，用hashset记录，最后转成vector的结果
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int> ans;
        unordered_set<int> tmp;
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i])!=m.end()){
                tmp.insert(nums2[i]);
            }
            
        }
        for(auto item:tmp){
            ans.push_back(item);
        }
        return ans;
    }
};