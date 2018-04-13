// 292. Nim Game
// 由提示可以知道如果当前只剩下4个，那必输，直接可以进行反向推导
// 可以得到：4 输  5，6,7赢 8输 9,10,11赢，这样就可以知道其实只要判断n%4==0就好了。 

class Solution {
public:
    bool canWinNim(int n) {
        return n%4==0? false:true;   
    }
};