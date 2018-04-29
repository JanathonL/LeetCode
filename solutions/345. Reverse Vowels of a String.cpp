// 345. Reverse Vowels of a String
// 定义i,j然后while(i<j) 先保证i,j都找到元音字符，注意这里元音字符是“aeiouAEIOU”,两两替换就好了
class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(!isVowel(s[i])){
                i++;
                continue;
            }
            if(!isVowel(s[j])){
                j--;
                continue;
            }
            if(isVowel(s[j])&&isVowel(s[i])){
                char tmp = s[j];
                s[j]=s[i];
                s[i]=tmp;
                i++;
                j--;
            }
        }
        return s;
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