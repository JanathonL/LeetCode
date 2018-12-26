378. Kth Smallest Element in a Sorted Matrix
class Solution {
public:
    // nlogn * log(max-min)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        while(l<r){
            int mid = l + (r-l)/2;
            int row = mid/n;
            int col = mid%n;
            int total = 0;
            for(int i=0;i<n;i++){
                total += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(total >= k){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};