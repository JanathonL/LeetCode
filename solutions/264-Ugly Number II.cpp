// 264. Ugly Number II
// 根据提示中的信息，我们知道丑陋序列可以拆分成3个子序列：
// 1x2, 2x2, 3x2, 4x2, 5x2, ...
// 1x3, 2x3, 3x3, 4x3, 5x3, ...
// 1x5, 2x5, 3x5, 4x5, 5x5, ...
// 每次从三个列表中取出当前最小的那个加入序列，直到第n个为止
class Solution {
public:
    int nthUglyNumber(int n) {
        int a,b,c;
        a=b=c=0;
        int cnt=1;
        int ans = 0;
        vector<int> result(1,1);
        while(cnt<n){
            result.push_back(min(min(result[a]*2,result[b]*3), result[c]*5));
            if(result.back() == result[a]*2) a++;
            if(result.back() == result[b]*3) b++;
            if(result.back() == result[c]*5) c++;
            cnt++;                    
        }
        return result.back();
        
    }
};