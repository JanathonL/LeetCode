// 246. Strobogrammatic Number
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// Example 1:

// Input:  "69"
// Output: true
// Example 2:

// Input:  "88"
// Output: true
// Example 3:

// Input:  "962"
// Output: false
class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        unordered_map<char,char> m;
        m['6']='9';
        m['8']='8';
        m['9']='6';
        m['1']='1';
        m['0']='0';
        string newnum;
        for(int i=0;i<num.size();i++){
            if(m.find(num[i])!=m.end())
                newnum+=m[num[i]];
            else
                return false;
        }
        reverse(newnum.begin(),newnum.end());
        return newnum==num;
        
    }
};