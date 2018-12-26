5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_length = -1;
        string ans = "";
        for(int i=0;i<n;i++){
            //odd
            int length = 0;
            // string tmp = "";
            int j = 0;
            for(j = 0;i-j>=0&&i+j<n;j++){
                if(s[i-j]==s[i+j]){
                    length++;
                }
                else{
                    break;
                }
            }
            length = 2*j-1;
            if(length>max_length){
                // cout<<"odd:"<<length<<endl;
                // length ++;
                max_length=2*j-1;
                ans=s.substr(i-j+1,2*j-1);
            }
            //even
            length=0;
            // tmp=""
            for(j = 0;i-j>=0&&i+1+j<n&&i+1<n;j++){
                if(s[i-j]==s[i+1+j]){
                    length++;
                    // cout<<"s[i-j]:"<<s[i-j]<<" s[i+1+j]:"<<s[i+1+j]<<endl;
                }
                else{
                    break;
                }
            }
            length = 2*j;
            if(length>max_length){
                // cout<<"even:"<<length<<endl;
                max_length=2*j;
                ans=s.substr(i-j+1,2*j);
            }
            
        }
        return ans;
    }
};