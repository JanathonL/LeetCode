730. Count Different Palindromic Subsequences
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        vector<vector<int>> chars(26, vector<int>());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            chars[S[i] - 'a'].push_back(i);
        }
        return helper(S, chars, 0, n, memo);
    }
    int helper(string S, vector<vector<int>>& chars, int start, int end, vector<vector<int>>& memo) {
        if (start >= end) return 0;
        if (memo[start][end] > 0) return memo[start][end];
        long res = 0;
        for (int i = 0; i < 26; ++i) {
            if (chars[i].empty()) continue;
            auto new_start = lower_bound(chars[i].begin(), chars[i].end(), start);
            auto new_end = lower_bound(chars[i].begin(), chars[i].end(), end) - 1;
            if (new_start == chars[i].end() || *new_start >= end) continue;
            ++res;
            if (new_start != new_end) ++res;
            res += helper(S, chars, *new_start + 1, *new_end, memo);
        }
        memo[start][end] = res % int(1e9 + 7);
        return memo[start][end];
    }
};