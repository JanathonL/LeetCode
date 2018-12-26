84. Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxsize = 0;
        heights.push_back(0); //为了把前面所有stack中的值都pop出来。
        for(int i =0;i<heights.size();){
            if(s.empty()){
                s.push(i++);
            }
            else{
                if(heights[s.top()]>=heights[i]){
                    int tmp  = s.top();
                    s.pop();
                    maxsize = max(maxsize,heights[tmp]*(s.empty()? i:i-s.top()-1));
                    // s.pop();
                }
                else{
                    s.push(i++);
                }
            }
        }
        return maxsize;
    }
};