240. Search a 2D Matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rown = matrix.size();
        int coln = matrix[0].size();
        cout<<"test1"<<endl;
        for(int deck = 0;deck<min(coln,rown);deck++){
            int first =0, last = coln+rown-2*deck-1;
            
            while(first!=last){
                
                int mid = (first+last) / 2;
                // cout<<"first:"<<first<<" last:"<<last<<" mid:"<<mid<<endl;
                int x,y;
                if(mid+deck <=rown-1){
                    x = mid;
                    y = deck;
                }
                else{
                    x = rown - deck-1;
                    y = mid - rown + 2*deck+1;
                }
                
                int val = matrix[x][y];
                // cout<<"x:"<<x<<" y:"<<y<<" val:"<<val<<endl;
                if(val==target) return true;
                if(val < target){
                    first = mid + 1;
                }
                else{
                    last = mid;
                }
            }
        }
        return false;
    }
};