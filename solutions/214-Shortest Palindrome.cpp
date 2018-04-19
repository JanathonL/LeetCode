// 214-Shortest Palindrome
// （1） 暴力：Time: O(n^2) 从end向0扫描，如果是回文就停止，否则就是end—重新开始扫，
//     最后把s.substr(end+1)的部分reverse一下加到s前面就好了
// （2） KMP算法，Time:O(n) 把s reverse一下变成rs， 然后l = s+”$”+rs，中间的分隔符是为了防止计算前缀出现问题。
// 这个想法的思路是，if s[0…i-1]是回文，那么 reverse(s[0…i-1]) == s[0…i-1].
// 之后要做的就算KMP的next数组
// 要注意，next[i]记录的是 s[0…i-1]中的最大前后缀长度（也就是回文最长长度）
// 最后只需要找到next[len-1]这个就是s的最长回文长度，把后面的reverse一下加到s前面就好了

class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(),rs.end());
        string l = s +"$"+ rs;
        int len = l.size();
        vector<int> next(len,0);
        for(int q=1,k=0;q<len;q++){
            while(k>0&&l[q]!=l[k]){
                k = next[k-1];
            }
            if(l[q]==l[k]){
                k++;
            }
            next[q]=k;
        }
        string tmp = s.substr(next[len-1]);
        reverse(tmp.begin(),tmp.end());
        string res = tmp+s;
        return res;
    }
};
// Time: O(n^2)
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int n = s.size();
//         bool flag = false;
//         int start,end;
//         start = 0;
//         end = n-1;
//         while(!flag&& start<end){
//             int i = end;
//             int j = start;
//             int isok=1;
//             for(i=end;i>=0&&j<i;){
//                 if(s[j]==s[i]) {
//                     j++;
//                     i--;
//                     continue;
//                 }
//                 else {
//                     isok=0;
//                     break;
//                 }
                
//                 // cout<<"i:"<<i<<" j:"<<j<<endl;
//             }
//             if(isok) flag = true;
//             else --end;
//             // cout<<"i:"<<i<<" j:"<<j<<" start:"<<start<<" end:"<<end<<" flag:"<<flag<<endl;
//         }
//         // cout<<end<<endl;
//         string patch = s.substr(end+1);
//         reverse(patch.begin(),patch.end());
//         s = patch+s;
//         return s;
//     }
// };