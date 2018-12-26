// 254. Factor Combinations
// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.

// Note:

// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Example 1:

// Input: 1
// Output: []
// Example 2:

// Input: 37
// Output:[]
// Example 3:

// Input: 12
// Output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// Example 4:

// Input: 32
// Output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> res;
        if(n==1) return res;
        dfs(n, cur, res);
        return res;
    }
    void dfs(int n, vector<int>& cur, vector<vector<int>>& res){
        if(n==1){
            if(cur.size()==1) return;
            res.push_back(cur);
            return ;
        }
        int start = 2;
        if(cur.size()!=0) start = cur[cur.size()-1]; 
        for(int i=start;i<=n;i++){
            if(n%i==0){
                cur.push_back(i);
                dfs(n/i, cur, res);
                cur.pop_back();
            }
        }
    }
};
/*
12
2 -> 6: 2 -> 3
3 -> 4
2,6
2,2,3
3,4
*/