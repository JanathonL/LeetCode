// 374. Guess Number Higher or Lower
// 二分法做，模板直接写就好了
// 注意算 mid的时候写成 mid=l+(h-l)/2防止溢出
//  
// 模板

// int l=1,h=n;
//         while(l<h){
//             int mid = l+(h-l)/2;            
//             if(guess(mid)==-1){
//                 h=mid-1;
//             }
//             else if(guess(mid)==1){
//                 l=mid+1;
//             }
//             else{
//                 return mid;
//             }
//         }
//         return l;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l=1,h=n;
        while(l<h){
            int mid = l+(h-l)/2;            
            if(guess(mid)==-1){
                h=mid-1;
            }
            else if(guess(mid)==1){
                l=mid+1;
            }
            else{
                return mid;
            }
        }
        return l;
    }
};