// 387. First Unique Character in a String
// 先用unordered_map存一下每个字符出现的次数，然后顺序遍历一下找到第一个只出现一次的字符就返回，否则就是返回-1
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};