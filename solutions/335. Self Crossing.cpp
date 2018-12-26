335. Self Crossing
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