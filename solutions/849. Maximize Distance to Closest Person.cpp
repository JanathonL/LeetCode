849. Maximize Distance to Closest Person


// refined beat 89%
// time: O(N)
// space: O(N)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size()==0) return 0;
        int len = seats.size();
        vector<int> left(seats.size(),len), right(seats.size(),len);
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                left[i] = 0;
            } else if(i>0){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==1){
                right[i] = 0;
            } else if(i<seats.size()-1){
                right[i] = right[i+1]+1;
            }
        }
        int res = 0;
        for(int i=0;i<seats.size();i++){
            res = max(res, min(right[i],left[i]));
        }
        return res;
    }
};



// refined 
// time: O(N)
// space: O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size()==0) return 0;
        int len = seats.size();
        int prev = -1;
        int future = 0;
        int res = 0;
        for(int i=0;i<len;i++){
            if(seats[i]==1){
                prev = i;
            } else {
                while(future < len && seats[future] == 0 || future < i){
                    future++;
                }
                int left = prev==-1? len:i-prev;
                int right = future==len? len:future-i;
                res = max(res, min(left, right));
            }
        }
        return res;
        
    }
};