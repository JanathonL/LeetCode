// 151. Reverse Words in a String
// 注意一下去掉多余的空格（虽然题目中没说）
// 思路就是利用三个变量，i,j,l .  i用来记录真实的s遍历位置，j记录当前结果字符串遍历位置，l记录当前这个word在结果字符串中的开始位置。
// 先每个word reverse一下，最后整体reverse一下

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