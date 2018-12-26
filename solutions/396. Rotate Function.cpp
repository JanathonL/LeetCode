396. Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        int allsum = 0;
        int F = 0;
        for(int i=0;i<len;i++){
            allsum += A[i];
            F += i*A[i];
        }
        int res = F;
        for(int i=1;i<len;i++){
            F = F + allsum - len*A[len-i];
            res = max(res, F);
        }
        return res;
    }
};