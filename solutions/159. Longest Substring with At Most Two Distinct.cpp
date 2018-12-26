159. Longest Substring with At Most Two Distinct Characters
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> m;
        int cnt=0;
        int start=0;
        int end =0;
        int result = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            
            if(m[s[i]]==1){
                cnt++;
            }
            if(cnt<=2){
                result = max(result, i-start+1);
            }
            else{
                while(1){
                    m[s[start]]--;
                    if(m[s[start]]==0){
                        start++;
                        cnt--;
                        result = max(result, i-start+1);
                        break;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        return result;
    }
};