74. Search a 2D Matrix
// refined
// solution 1
// time: O(log(m*n))
// space: O(1)
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

// refined
// solution 2
// beat 49%
// time: O(N+logm)
// space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowlen = matrix.size();
        if(rowlen==0) return false;
        int collen = matrix[0].size();
        if(collen == 0) return false;
        int row = 0, col = collen - 1;
        while(row<rowlen && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};