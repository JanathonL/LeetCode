// 132. Palindrome Partitioning II
// DP: Time: O(n^2),  Space: O(n^2)
// 定义两个变量
// pal[i][j]表示 str[i…j] 是否是palindrome
// d[i] 表示 str[i…n-1] 的min cut，注意这里d[i]初始化为最坏情况n-i-1, 0<=i<=n
// if str[i]==str[j] &&(j-i<2||str[i+1][j-1]):  
// 		pal[i][j]=true
// 		d[i] = min(d[i],d[j+1]+1); 
// 		//相当于在j这个地方切一刀，但是要算d[j+1]+1，而不是d[j]+1;

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
