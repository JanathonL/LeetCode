// 372. Super Pow
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a % 1337 == 0) return 0; // this line could also be removed
        int p = 0;
        for (int i : b) p = (p * 10 + i) % 1140;
        if (p == 0) p += 1140;
        return power(a, p, 1337);
    }
    int power(int x, int n, int mod) {
        int ret = 1;
        for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
        return ret;
    }
};