// 343. Integer Break
// 找规律的题
// (1) DP: Time: O(n)  可以发现f[7] = f[4]*3,  f[8]=f[5]*3;以此类推
// (2) 发现n是先拆分成3，之后看剩余的是2还是4，之后全部乘起来就好了

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        int sum=1;
        while(n!=2&&n!=4&&n!=0){
            sum*=3;
            n-=3;
        }
        if(n!=0){
            return sum*n;
        }
        else{
            return sum;
        }
        
    }
};
// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> ans = {0,0,1,2,4,6,9};
//         for(int i=7;i<=n;i++){
//             ans.push_back(ans[i-3]*3);
//         }
//         return ans[n];
//     }
// };