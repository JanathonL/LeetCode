360. Sort Transformed Array
class Solution {
public:
    /*
    a > 0 
    from begin and end put bigger to res
    a < 0
    from begin and end put smaller to res
    a == 0
    go through from begin to end 
    if(res.back() > res.front()) reverse
    
    8 min
    bug free
    time: O(N)
    space: O(1);
    */
    
    int cal(int x, int a, int b, int c){
        return a*x*x+b*x+c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if(nums.size()==0){
            return res;
        }
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end){
            int temp_s = cal(nums[start], a, b, c);
            int temp_e = cal(nums[end], a, b, c);
            if(a>0){
                if(temp_s>=temp_e){
                    res.push_back(temp_s);
                    start++;
                } else {
                    res.push_back(temp_e);
                    end--;
                }
            } else {
                if(temp_s>=temp_e){
                    res.push_back(temp_e);
                    end--;
                } else {
                    res.push_back(temp_s);
                    start++;
                }
            }
        }
        if(res.back()<res.front()){
            reverse(res.begin(), res.end());
        }
        return res;
    }
};