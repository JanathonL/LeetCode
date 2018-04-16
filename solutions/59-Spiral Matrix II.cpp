// 59. Spiral Matrix II
// （1）	和spiral matrix解法一模一样
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n,0));
        int rb,re,cb,ce;
        rb=cb=0;
        re=ce=n-1;
        int cnt=1;
        while(true){
            // l to r
            for(int j=cb;j<=ce;j++) m[rb][j]=cnt++;
            if(++rb > re) break;
            // t to d
            for(int i=rb;i<=re;i++) m[i][ce]=cnt++;
            if(cb > --ce) break;
            // r to left
            for(int j=ce;j>=cb;j--) m[re][j]=cnt++;
            if(rb > --re) break;
            // d to t
            for(int i=re;i>=rb;i--) m[i][cb]=cnt++;
            if(++cb > ce) break;
        }
        return m;
    }
};