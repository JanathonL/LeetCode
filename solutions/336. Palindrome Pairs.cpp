336. Palindrome Pairs
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