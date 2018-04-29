// 824. Goat Latin
// 字符串模拟一下就好了

class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> ans;
        for(int i=0;i<S.size();i++){
            if(S[i]==' ') continue;
            int j = S.find_first_of(" ",i);
            // cout<<j<<endl;
            
            string tmp = S.substr(i,j-i);
            
            i=j;
            ans.push_back(tmp);
            if(j==-1) break;
        }
        string res;
        for(int i=0;i<ans.size();i++){
            if(isVowel(ans[i][0])){
                ans[i].append("ma");
                
            }
            else{
                string tmp = ans[i].substr(1);
                tmp+=ans[i][0];
                ans[i]=tmp;
                ans[i].append("ma");
            }
            for(int j=0;j<=i;j++){
                ans[i].append("a");
            }
            if(res=="")
                res+= ans[i];
            else{
                res+= " "+ans[i];
            }
        }
        return res;
    }
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
        else{
            return false;
        }
    }
};