260. Single Number III
/*
get z = x^y
get one bit different  m = (z&(z-1))^z
partition the array to two sets if((n&m) != 0)
use oxr to get the result
4 wrongs
15 min
time: O(N)
space: O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int z = 0;
        for(int n:nums){
            z = z^n;
        }
        int m = (z&(z-1))^z;  // 注意这个地方取最后一位1是要异或原来本身的
        int first = 0;
        int second = 0;
        for(int n:nums){
            if((n&m) != 0){
                first = first^n;
            } else {
                second = second^n;
            }
        }
        return {first, second};
    }
};