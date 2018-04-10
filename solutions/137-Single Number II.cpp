// 137. Single Number II
// 方法1：创建一个长度为sizeof(int)的数组count[sizeof(int)]，count[i]表示在在i位出现的1的次数。
// 如果count[i]是3的整数倍，则忽略；否则就把该位取出来组成答案。

// 方法2：用one记录到当前处理的元素为止，二进制1出现“1次”（mod 3 之后的 1）的有哪些二进制位；
// 用two记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的有哪些二进制位。
// 当one和two中的某一位同时为1时表示该二进制位上1出现了3次，此时需要清零。即用二进制模拟三进制运算。
// 最终one记录的是最终结果。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt = sizeof(int)*8;
        vector<int> d(cnt,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<cnt;j++){
                d[j] += (nums[i]>>j) & 1;
                d[j] %= 3;
            }
        }
        int result=0;
        for(int i=0;i<cnt;i++){
            result += (d[i]<<i);
        }
        return result;
    }
};
// // Single Number II
// // 方法2，时间复杂度O(n)，空间复杂度O(1)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int one = 0, two = 0, three = 0;
//         for (int i : nums) {
//             two |= (one & i);
//             one ^= i;
//             three = ~(one & two);
//             one &= three;
//             two &= three;
//         }

//         return one;
//     }
// };
