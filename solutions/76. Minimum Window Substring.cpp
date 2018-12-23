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
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        unordered_map<char, int> seen;
        for(int i=0;i<t.size();i++){
            dict[t[i]]++;
        }
        int require = dict.size();
        int unique = 0;
        int start = 0;
        int end = 0;
        int min_len = INT_MAX;
        string res;
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
                    res = s.substr(start, end-start+1);
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
        return res;
    }
};