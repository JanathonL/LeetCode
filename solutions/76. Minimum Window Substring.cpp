76. Minimum Window Substring
/*
sliding window -> two pointers start and end
hash table dict -> T
require -> num of distinct num in T
hash table seen -> the char in S
unique -> num of unique in seen
while(unique==require){
    rm char in seen
    update unique
    move start forward
}

bug free
11 min
time: O(n)
space: O(n)
*/
// refined
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        unordered_map<char, int> seen;
        for(int i=0;i<t.size();i++){
            dict[t[i]]++;
        }
        int require = dict.size();
        int unique = 0, start = 0, end = 0, min_len = INT_MAX;
        string res;
        int res_start = 0;
        while(end < s.size()){
            // update seen and unique
            int c = s[end];
            seen[c]++;
            if(dict.count(c) && seen[c]==dict[c]){
                unique++;
            }
            while(unique==require){
                // rm char in seen
                if(end-start+1<min_len){
                    res_start = start;
                    min_len = end-start+1;
                }
                c = s[start];
                seen[c]--;
                if(dict.count(c)&&seen[c]<dict[c]){
                    unique--;
                }
                // update start
                start++;
            }
            // update end
            end++;
        }
        return min_len!=INT_MAX? s.substr(res_start, min_len):"";
    }
};