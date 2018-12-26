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