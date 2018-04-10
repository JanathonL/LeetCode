// 89. Gray Code
// 可以直接从之前的码进行推广
// 1的gray code : 0 1
// 2 的 gray code : 0 1 -> (00 01) (11 10)
// 最高位为1，然后反向顺序添加
// 自然二进制码转换为格雷码： g0=b0,gi=bi ^ bi−1
// 保留自然二进制码的最高位作为格雷码的最高位，格雷码次高位为二进制码的高位与次高位异或，其余各位与次高位的求法类似。例如，将自然二进制码1001，转换为格雷码的过程是：保留最高位；然后将第1位的1和第2位的0异或，得到1，作为格雷码的第2位；将第2位的0和第3位的0异或，得到0，作为格雷码的第3位；将第3位的0和第4位的1异或，得到1，作为格雷码的第4位，最终，格雷码为1101。
// 格雷码转换为自然二进制码： b0=g0,bi=gi ^ bi−1
// 保留格雷码的最高位作为自然二进制码的最高位，次高位为自然二进制高位与格雷码次高位异或，其余各位与次高位的求法类似。例如，将格雷码1000转换为自然二进制码的过程是：保留最高位1，作为自然二进制码的最高位；然后将自然二进制码的第1位1和格雷码的第2位0异或，得到1，作为自然二进制码的第2位；将自然二进制码的第2位1和格雷码的第3位0异或，得到1，作为自然二进制码的第3位；将自然二进制码的第3位1和格雷码的第4位0异或，得到1，作为自然二进制码的第4位，最终，自然二进制码为1111。
// 格雷码有数学公式，整数n的格雷码是n^ (n/2)。
// 这题要求生成n比特的所有格雷码。
// 方法1，最简单的方法，利用数学公式，对从 0∼2n−1的所有整数，转化为格雷码。
// 方法2，n比特的格雷码，可以递归地从n-1比特的格雷码生成。如下图所示。

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i =0;i<n;i++){
            int sz = result.size();
            for(int k=sz-1;k>=0;k--){
                result.push_back(result[k] | 1<<i);
            }
        }
        return result;
    }
};