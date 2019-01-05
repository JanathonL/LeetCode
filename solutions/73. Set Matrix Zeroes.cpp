73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set< pair<int,int> > myset;
        set< pair<int,int> >::iterator it;
        cout<<"test"<<endl;
        int rown=matrix.size();
        int coln=matrix[0].size();
        for(int i =0;i<rown;i++){
            for(int j=0;j<coln;j++){
                if(matrix[i][j]==0){
                    myset.insert(make_pair(i,j));
                }
            }
        }
        for(it=myset.begin();it!=myset.end();it++){
            int target_row = (it->first);
            int target_col = (it->second);
            for(int k = 0;k<rown;k++){
                matrix[k][target_col]=0;
            }
            for(int k=0;k<coln;k++){
                matrix[target_row][k]=0;
            }
        }
    }
};

// refined
// beat 50%
// time: O(n*m)
// space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size();
        if(rowlen==0) {
            return;
        }
        int collen = matrix[0].size();
        if(collen==0) return;
        bool firstRow = false, firstCol = false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                firstCol = true;
                break;
            }
        }
        for(int j=0;j<collen;j++){
            if(matrix[0][j]==0){
                firstRow = true;
                break;
            }
        }
        for(int i=0;i<rowlen;i++){
            for(int j=0;j<collen;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<rowlen;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<collen;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=1;j<collen;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<rowlen;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRow){
            for(int j=0;j<collen;j++){
                matrix[0][j] = 0;
            }
        }
        if(firstCol){
            for(int i=0;i<rowlen;i++){
                matrix[i][0] = 0;
            }
        }
    }
};