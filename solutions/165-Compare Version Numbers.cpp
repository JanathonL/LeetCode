// 165. Compare Version Numbers
// 这题的坑就是，不一定只有一个小数点，可能有无穷多个小数点
// Time: O(n) 做法是每次都把当前小数点之前的数算出来，然后再比较，如果相等，i++,j++，跳过小数点，然后下一轮比较。

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0; 
        int j = 0;
        int n1 = version1.size(); 
        int n2 = version2.size();

        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }

            while(j<n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0');;
                j++;
            }

            if(num1>num2) return 1;
            else if(num1 < num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }

        return 0;
    }
};