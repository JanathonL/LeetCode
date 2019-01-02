42. Trapping Rain Water
/*
find left highest
find right highest
max(0, min(left[i], right[i])-height[i])

refined
beats: 14.87%
4 min
bug free!!
time: O(N)
space: O(N)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) {
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i=1;i<n;i++){
            left[i] = max(height[i-1], left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(height[i+1],right[i+1]);
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += max(0, min(left[i],right[i])-height[i]);
        }
        return sum;
    }
};