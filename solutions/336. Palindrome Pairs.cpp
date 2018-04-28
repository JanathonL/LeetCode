// 336. Palindrome Pairs
// Time: O(n*k*k) 
// 解题思路是，我先遍历每个word，组成str1,str2，注意这边str1和str2都是可能为空或者是等于word本身的。找到回文的部分，然后剩下的部分去map中找能不能找到，判断逻辑
// if(isPalindrome(str1)){
//                     reverse(str2.begin(),str2.end());
//                     if(m.find(str2)!=m.end()&&m[str2]!=i){
//                         ans.push_back({m[str2],i});
//                     }
//                    }
// 		对应的情况是 “cbcab”  “ba” 此时 str1=cbc str2=ab  这时候就是找到 “bacbcab”
// 然后注意一下，如果选择str1为空的判断过之后，str2为空的情况应该跳过，不然的话会有重复出现。
// “abcd”  “dcba”  这种时候如果str1和str2为空都判断的话，会出现重复计算。
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        if(words.size()<2) return ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]=i;
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<=words[i].size();j++){
                string str1 = words[i].substr(0,j);
                string str2 = words[i].substr(j);
                if(isPalindrome(str1)){
                    reverse(str2.begin(),str2.end());
                    if(m.find(str2)!=m.end()&&m[str2]!=i){
                        ans.push_back({m[str2],i});
                    }
                }
                if(str2.size()!=0&&isPalindrome(str2)){
                    reverse(str1.begin(),str1.end());
                    if(m.find(str1)!=m.end()&&m[str1]!=i){
                        ans.push_back({i,m[str1]});
                    }
                }
            }
        }
        return ans;
    }
    bool isPalindrome(string str){
        if(str=="") return true;
        int i =0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};