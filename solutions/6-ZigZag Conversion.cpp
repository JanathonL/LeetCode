// 6. ZigZag Conversion
// 要找到数学规律。真正面试中，不大可能出这种问题。
// n=4:

// P     I      N
// A  L  S   I  G
// Y A   H R
// P     I
// n=5:

// P       H
// A     S I
// Y   I   R
// P L     I  G
// A       N
// 所以，对于每一层垂直元素的坐标 (i,j)= (j+1 )*n +i；
// 对于每两层垂直元素之间的插入元素（斜对角元素），(i,j)= (j+1)*n -i
// 一行一行遍历，每次都先添加垂直元素，然后再添加后面的斜对角线元素，
// 注意，第一行和最后一行的斜对角线元素不能添加因为和垂直元素相同。

// Time O(n)，space: O(1)
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1 || s.size() <= 1) return s;
        string result;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0, index = i; index < s.size();
                    j++, index = (2 * nRows - 2) * j + i) {
                result.append(1, s[index]);  // verticle element
                if (i == 0 || i == nRows - 1) continue;   // prevent the double calculation
                // diagnal element
                if (index + (nRows - i - 1) * 2 < s.size())
                    result.append(1, s[index + (nRows - i - 1) * 2]);
            }
        }
        return result;
    }
};