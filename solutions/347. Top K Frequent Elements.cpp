347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int, int> frequencyMap;

        for (int n : nums) {
            frequencyMap[n]++;
        }

        for (auto item : frequencyMap) {
            int key = item.first;
            int freq = frequencyMap[key];
            bucket[freq].push_back(key);
        }

        vector<int> res;

        for (int pos = bucket.size() - 1; pos >= 0 && res.size() < k; pos--) {
            if (bucket[pos].size()!=0) {
                for(int item : bucket[pos]){
                    res.push_back(item);
                }
            }
        }
        return res;
    }
};
