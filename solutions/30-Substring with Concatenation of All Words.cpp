// 30. Substring with Concatenation of All Words
// 这题和之前有一道题的思路很像，
// 用两个map，expected和appeared，
// expected表示这个word预计出现多少次，appeared表示这个word已经出现了多少次
// 之后就是两个for循环，这题的做法是，
// 直接以len的长度去扫当前i开始的字符串，如果都满足expected的次数，而且都找的到的话，
// 就push_back(i),否则break，i++;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0||s.size()==0) return vector<int>();
        vector<int> result;
        unordered_map<string,int> expected;
        
        for(int i=0;i<words.size();i++){
            if(expected.find(words[i])==expected.end()){
                expected[words[i]]=1;
            }
                
            else{
                expected[words[i]]++;
            }
                
        }
        int appear = 0;
        int n = s.size();
        int num = words.size();
        int len = words[0].size();
        int i,j;
        for(i = 0;i<n-num*len+1;i++){
            unordered_map<string,int> appeared;
            for(j=0;j<num;j++){
                string tmp = s.substr(i+j*len,len);
                if(expected[tmp]>0){
                    appeared[tmp]++;
                    if(appeared[tmp]>expected[tmp]){
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(j==num) result.push_back(i);
            
        }
        return result;
    }
};