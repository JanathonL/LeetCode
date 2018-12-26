// 605. Can Place Flowers
// Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False
// Note:
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        for(int i=0;i<fb.size();i++){
            if(i==0 && fb[i]!=1 ){
                if(i+1<fb.size() && fb[i+1]!=1){
                    fb[i] = 1;
                    n--;
                }
                else if(i+1>= fb.size()){
                    fb[i] = 1;
                    n--;
                }
            }
            else if(i==fb.size()-1){
                if(fb[i]==0 && fb[i-1]==0){
                    fb[i] = 1;
                    n--;
                }
            }
            else{
                if(fb[i-1]==0&&fb[i]==0&&fb[i+1]==0){
                    fb[i] = 1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};