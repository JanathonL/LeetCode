// 335. Self Crossing
// 这题纯是找规律的
// 有两种明显的情况，一种是外螺旋，一种是内螺旋，都是不会相遇的。
// 外螺旋的判断标准就是: i>=2时， x[i]>x[i-2] 
// 内螺旋的判断标准是：i>=2时， x[i]<x[i-2]
// 如果先内螺旋再外螺旋 必然相交
// 如果先外螺旋再内螺旋需要判断一下
// (1)	如果x[i]+x[i-4]>=x[i-2]那么这时候，判断的边界x[i-1]要变成x[i]-x[i-3]可以画图看看
// (2)	否则就是不用变 x[i-1]=x[i-1]
// 注意一点就是，先用x[2]>x[0]判断一下一开始是什么螺旋 flag标记一下，然后等到外螺旋变内螺旋了，flag又标记一下。
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size()<=3) return false;
        bool flag = x[2]>x[0];
        for(int i=3;i<x.size();i++){
            if(!flag&&x[i]>=x[i-2]) return true;
            if(flag&&x[i]<=x[i-2]){
                flag = false;
                int tmp= i==3? 0:x[i-4];
                if(x[i]+tmp>=x[i-2]){
                    x[i-1]=x[i-1]-x[i-3];
                }
            }
        }
        return false;
    }
};