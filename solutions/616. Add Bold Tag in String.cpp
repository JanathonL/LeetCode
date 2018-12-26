616. Add Bold Tag in String
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        else{
            return a.second<b.second;
        }
    }
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        int n = s.size();
        int end = INT_MIN;
        vector<bool> bold(n,false);
        for(int i=0;i<n;i++){
            for(string word:dict){
                int len = word.size();
                if(i+len<=n && s.substr(i,len)==word){
                    end = max(end, i+len);
                }
            }
            bold[i]=end>i;
        }
        string res;
        for(int i=0;i<n;i++){
            if(bold[i]==false){
                res += s[i];
                continue;
            }
            int j=i;
            while(j<n && bold[j]==true){
                j++;
            }
            res += "<b>"+s.substr(i,j-i)+"</b>";
            i = j-1;
        }
        return res;

    }
};