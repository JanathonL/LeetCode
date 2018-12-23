3. Longest Substring Without Repeating Characters
/*
use two pointers as sliding window
start end
if set can find str[end]
    set will erase the str[start], move start forward 
    until str[start] == str[end]
    set.erase(str[start])
    start++
add the str[end] to hash set
maintain max_len
end++;

return max_len
time: O(N)
"abcabcbb"
size of str = 8
start = 7;
end = 7;
max_len = 3
seen:     b
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // check empty
        if(s=="") return 0;
        int start = 0;
        int end = 0;
        int max_len = INT_MIN;
        unordered_set<char> seen;
        while(end<s.size()){
            if(seen.count(s[end])){
                while(s[start]!=s[end]){
                    seen.erase(s[start]);
                    start++;
                }
                seen.erase(s[start]);
                start++;
            }
            // add the str[end] to hash set
            seen.insert(s[end]);
            // maintain max_len
            max_len = max(max_len, end-start+1);
            end++;
        }
        return max_len;
    }
};