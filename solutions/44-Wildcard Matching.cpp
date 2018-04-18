// 44. Wildcard Matching
// 可以使用上面那题递归的思路做，但是会超时
// 也可以使用DP的思路做
// DP:
// f[i][j] 表示 p[0…i-1] 和 s[0…j-1]是否匹配
// f[i][j] = p[i-1][j-1]&&( '?'==p[i-1]||s[j-1]==p[i-1])   if ‘*’ != p[i-1]
// f[i][j] = f[i][j-1] || f[i-1][j];  if ‘*’ == p[i-1]
// 初始化是f[0][0] = true;
// f[i][0] = f[i-1][0] && ‘*’ == p[i-1]    p和空串匹配的话，只能是‘*’,而且在这之前的匹配不能是false
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> f(n+1,vector<bool>(m+1,false));
        f[0][0]=true;
        for(int i=1;i<=n;i++){
            f[i][0]= f[i-1][0]&&'*'==p[i-1];
            for(int j=1;j<=m;j++){
                f[0][j]=false;
                if('*'==p[i-1]){
                    f[i][j]=f[i][j-1]||f[i-1][j];
                }
                else{
                    f[i][j]=f[i-1][j-1]&&('?'==p[i-1]||s[j-1]==p[i-1]);
                }
            }
        }
        return f[n][m];
    }
};
// 递归版本超时
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if(p.size()==0) return s.size()==0;
//         int i=0;
//         while('*'==p[i]&&i<p.size()-1&&'*'==p[i+1]){
//             i++;
//         }
        
//         if('*'==p[i]){
//             return isMatch(s,p.substr(i+1))||s.size()>0&&isMatch(s.substr(1),p);
//         }
//         else{
//             if(s.size()==0) return false;
//             else{
//                 return (s[0]==p[0]||'?'==p[0])&&isMatch(s.substr(1),p.substr(1));
//             }
//         }
//     }
// };