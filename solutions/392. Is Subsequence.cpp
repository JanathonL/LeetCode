392. Is Subsequence
class Solution {
public:
    /*
    3 min
    two pointers
    bug free
    time: O(N)
    space: O(1)
    
    If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
    hash table <key(char), vector<int>(index)> 
    go through S
    find key use binary search to find first index in T >= cur_index in S
    n log k (n is the num of s, k is avg index for a char)
    */
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(int i=0;i<t.size() && index<s.size();i++){
            if(t[i]==s[index]){
                index++;
            }
        }
        return index==s.size();
    }
};