11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int result = 0;
        while(start<end){
            result = max(result, min(height[start],height[end])*(end-start));
            if(height[start]<=height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return result;
    }
};