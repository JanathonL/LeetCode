390. Elimination Game
// 这题可以使用递归解决，每次都消除一半，剩下的数可能是原来未删除的数，或者是原来的数+1然后除以2.
// 所以就可以进行递归
// last(n, left to right):

// if(n==1)  return 1;
// if(left to right){
// 		return 2*last(n/2, false);
// }
// else{
// 		if(n%2==0){
// 			return 2*last(n/2,true)-1;      1 2 3 4 ->  1  3    (1 2)
// 		}
// 		else{
// 			return 2*last(n, true);         1 2 3 4 5 ->  2 4    (1 2)
// 		}
// }
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