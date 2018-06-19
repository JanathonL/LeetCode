// 389. Find the Difference
// 先用unordered_map存一下s每个字符出现的次数，然后顺序遍历一下t，每次都m[t[i]]--,然后找到m[t[i]] == -1的字符返回
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            m[t[i]]--;
            if(m[t[i]]==-1){
                return t[i];
            }
        }
        return 'c';
    }
};