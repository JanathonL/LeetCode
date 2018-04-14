class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> expected,appeared;
        int i = 0;
        while(i<t.size()) {
            if(expected.find(t[i])==expected.end()){
                expected[t[i]]=1;
            }
            else{
                expected[t[i]]++;
            }
            i++;
        }
        int word_s=0;
        int appear = 0;
        string res;
        int minlen = INT_MAX;
        for(int word_e = 0;word_e<s.size();word_e++){
            
            if(expected.find(s[word_e])!=expected.end()){
                if(appeared.find(s[word_e])==appeared.end()){
                    appeared[s[word_e]]=1;
                }
                else{
                    appeared[s[word_e]]++;
                }
                if(appeared[s[word_e]]<=expected[s[word_e]]){
                    appear++;
                }
                
            }
            // cout<<s.substr(word_s,word_e-word_s+1)<<endl;
            
            if(appear==t.size()){
                
                while(appeared.find(s[word_s])==appeared.end()|| appeared[s[word_s]]<=0 || appeared[s[word_s]] > expected[s[word_s]]){
                    // cout<<appeared[s[word_s]]<<" s[word_s]:"<<s[word_s]<<endl;
                    appeared[s[word_s]]--;
                    word_s++;
                    bool tmp = (appeared.find(s[word_s])==appeared.end());
                    // cout<<"tmp:"<<tmp<<" s[word_s]:"<<s[word_s]<<endl;
                }
                if(word_e-word_s+1<minlen){
                    minlen = word_e - word_s+1;
                    res = s.substr(word_s,minlen);
                }
            }
            // cout<<s.substr(word_s,word_e-word_s+1)<<endl;
            // cout<<appeared[s[word_e]]<<" s[word_e]:"<<s[word_e]<<endl;
        }
        if(minlen==INT_MAX) return "";
        return res;
    }
};
