413. Arithmetic Slices
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        vector<int> dp(len,0);
        int cnt = 0;
        for(int i=0;i<len-2;i++){
            if(A[i+1]-A[i]== A[i+2]-A[i+1]){
                dp[i+2]=true;
                cnt++;
            }
            for(int j=i+3;j<len;j++){
                dp[j]= dp[j-1]&& (A[j]-A[j-1])==(A[j-1]-A[j-2]);
                if(dp[j]==true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};