74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rown = matrix.size();
        int coln = matrix[0].size();
        int first = 0, last = rown * coln;
        while(first!=last){
            int mid = (first+last)/2;
            int x= mid/coln;
            int y= mid%coln;
            if(target == matrix[x][y]) return true;
            if(matrix[x][y] < target){
                first = mid + 1;
            }
            else{
                last = mid;
            }
        }
        return false;
    }
};