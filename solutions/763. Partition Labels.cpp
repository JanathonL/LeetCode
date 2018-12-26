763. Partition Labels
class Solution {
public:
    
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]] = i;
        }
        int i=0;
        vector<int> res;
        int n = s.size();
        while(i<n){
            int left = i, right = i;
            while(left <= right){
                right = max(right, m[s[left]]);
                left++;
            }
            res.push_back(right - i+1);
            i = left;
        }
        return res;
    }
};