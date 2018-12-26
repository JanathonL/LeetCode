132. Palindrome Partitioning II
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<vector<bool>> pal(n,vector<bool>(n,0));
        vector<int> d(n+1,-1);
        for(int i =0;i<n+1;i++){
            d[i]=n-i-1;
        }
        for(int i =n-1;i>=0;i--){
            
            for(int j = i;j<n;j++){
                if(s[j]==s[i]&&(j-i<2||pal[i+1][j-1])){
                    pal[i][j]=true;
                    // cout<<"i:"<<i<<" j:"<<j<<" true"<<endl;
                    d[i]=min(d[i],d[j+1]+1);
                }
            }
        }
        return d[0];
        
    }
};