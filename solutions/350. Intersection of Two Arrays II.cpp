// 350. Intersection of Two Arrays II
// O(n) 用hashmap记录一下有哪些值，然后第二个数组遍历一下，用vector记录出现的值，每次出现就把map[nums2[i]--。
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int> ans;
        
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]>0){
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            }
            
        }
        return ans;
    }
};