// refined 
// beat 28.36%
// time: O(N^2)
// space: O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        // initialize a dictionary that stores 1, 2, ..., n. This string will store the permutation.
        string dict(n, 0);
        iota(dict.begin(), dict.end(), '1');
        
        // build up a look-up table, which stores (n-1)!, (n-2)!, ..., 1!, 0!
        vector<int> fract(n, 1);
        for (int idx = n - 3; idx >= 0; --idx) {
            fract[idx] = fract[idx + 1] * (n - 1 - idx);
        }
        
        // let k be zero base
        --k;
        
        // the main part.
        string ret(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            int select = k / fract[idx];
            k %= fract[idx];
            ret[idx] = dict[select];
            dict.erase(next(dict.begin(), select)); // note that it is an O(n) operation
        }
        return ret;
    }
};