390. Elimination Game
class Solution {
public:
    int lastRemaining(int n) {
        return last(n,true);
    }
    int last(int n, bool lr){
        if(n==1){
            return 1;
        }
        if(lr){
            
            return 2*last(n/2,false);
        }
        else{
            if(n%2==0){
                return 2*last(n/2,true)-1;
            }
            else{
                return 2*last((n-1)/2,true);
            }
        }
    }
};