395. Longest Substring with At Least K Repeating Characters
class Solution {
public:
    /*
    50 min
    tricky
    space: O(N)
    time: O(kN) k is the char whose frequency is less than k
        
    */
    int longestSubstring(string s, int k) {
        if(s.size() < k) return 0;
        unordered_map<char,int> m; // char -> freq
        if(least_times(s, m) >= k) return (int) s.size();
        int result = 0;
        vector<int> indexes;
        for(int i = 0;i<s.size();i++){
            if(m[s[i]] < k) indexes.push_back(i);
        }
        int start = 0;
        for(int i = 0; i < indexes.size();i++){
            string potential = s.substr(start,indexes[i] - start);
            start = indexes[i] + 1;
            result = max(result, longestSubstring(potential,k));
        }
        string potential = s.substr(start,s.size() - start);
        result = max(result, longestSubstring(potential,k));
        return result;
    }
    int least_times(string a, unordered_map<char,int>& m){ // calculate least time of a string
        if(a.empty()) return 0;
        int r = INT_MAX;
        for(int i = 0;i<a.size();i++){
            m[a[i]]++;
        }
        for(auto iter = m.begin();iter!=m.end();++iter){
            r = min(r, iter->second);
        }
        return r;
    }
};