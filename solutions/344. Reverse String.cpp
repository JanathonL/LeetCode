// 344. Reverse String
// 定义i,j然后while(i<j) 两两替换就好了
class Solution {
public:
    string reverseString(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            char tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
            i++;
            j--;
        }
        return s;
    }
};