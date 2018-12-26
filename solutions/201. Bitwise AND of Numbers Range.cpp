201. Bitwise AND of Numbers Range
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt=0;
        while(n>m){
            cnt++;
            m=(m>>1);
            n=(n>>1);
        }
        return m<<cnt;
    }
};