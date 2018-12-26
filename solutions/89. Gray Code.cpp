89. Gray Code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i =0;i<n;i++){
            int sz = result.size();
            for(int k=sz-1;k>=0;k--){
                result.push_back(result[k] | 1<<i);
            }
        }
        return result;
    }
};