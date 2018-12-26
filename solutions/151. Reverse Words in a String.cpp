151. Reverse Words in a String
class Solution {
public:
    void reverseWords(string &s) {
        int i,j;
        i=0;
        j=0;
        int cnt=0;
        while(true){
            while(s[i]==' ') i++;
            if(i==s.size()) break;
            if(cnt) s[j++]=' ';
            int l=j;
            while(i<s.size()&&s[i]!=' '){
                s[j]=s[i];
                i++;j++;
            }
            cnt++;
            reverse(s.begin()+l,s.begin()+j);
        }
        s.resize(j);
        reverse(s.begin(),s.end());
    }
};