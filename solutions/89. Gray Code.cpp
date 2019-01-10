89. Gray Code

// REFINED
// beat 89%
// time: O(N^2)
// space: O(1)
// everytime, set the highest bit to 1, in reverse order
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