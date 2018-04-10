// 191. Number of 1 Bits
// 最直接的方法，做32次右移，统计出1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=0;i<32;i++){
            if(n&1){
                cnt++;
            }
            n=n>>1;
                    
        }
        return cnt;
    }
};