// 10. Regular Expression Matching
// 递归，每次都判断一下后面那个符号是不是’*’，如果是的话有两种可能，
// 第一种是，当前p[0],p[1]（x*）舍弃，直接比较isMatch(s,p.substr(2)). 
// 第二种是不舍弃比较一下当前的这个符号是否一样，一样的话或者’.’==p[0]，那可以比较 isMatch(s.substr(1), p)
// 如果后面那个符号不是‘*’，那么先判断一下s是否为空，是的话就直接return false
// 否则就是判断一下 (s[0]==p[0]||’.’==p[0])&&isMatch(s.substr(1),p.substr(1))
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0) return s.size()==0;
        
        if('*'==p[1]){
            return isMatch(s,p.substr(2))||s.size()>0&&(s[0]==p[0]||'.'==p[0])&&isMatch(s.substr(1),p);
        }
        else{
            if(s.size()==0) return false;
            else{
                return (s[0]==p[0]||'.'==p[0])&&isMatch(s.substr(1),p.substr(1));
            }
        }
    }
};