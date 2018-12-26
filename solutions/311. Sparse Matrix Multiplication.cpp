311. Sparse Matrix Multiplication
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if(A.size()==0||A[0].size()==0) {
            return res;
        }
        if(B.size()==0||B[0].size()==0){
            return res;
        }
        res.resize(A.size(), vector<int>(B[0].size(), 0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==0) continue;
                for(int k=0;k<B[0].size();k++){
                    res[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return res;
    }
};