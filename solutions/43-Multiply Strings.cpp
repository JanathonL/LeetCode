// 43. Multiply Strings
// （1）	正常思路，一步一步模拟，但是我在乘完得到tmp字符串之后使用的是大数相加的函数，
// 导致时间复杂度很高O(n^4)
// （2）	可以直接开辟一个新的字符串，string sum(num1.size()+num2.size(),’0’),
//  然后两个数都从后往前模拟相乘，注意要把字符串s[i+j+1]原来的数也要加上去，
//  然后每一轮相乘之后要把carry赋值在s[i+0]位（这位之前都是‘0’）； Time:O(n^2)
class Solution {
public:
    string multiply(string num1, string num2) {
        int n2 = num2.size();
        string sum(num1.size()+num2.size(),'0');
        for(int i =num1.size()-1; 0<=i ;--i){         
            int carry = 0;
            for(int j = num2.size()-1;0<=j;--j){
                int tmp = sum[i+j+1]-'0'+ (num1[i]-'0')*(num2[j]-'0')+carry;
                sum[i+j+1]=tmp%10+'0';
                carry = tmp/10;
            }
            sum[i]+=carry;
        }
        auto it = sum.find_first_not_of('0');
        if(string::npos != it){
            return sum.substr(it);
        }
        return "0";
    }
};
// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         int n2 = num2.size();
//         string sum;
//         for(int i =0;i<num1.size();i++){
//             string tmp;
//             int a=num1[i]-'0';
//             int carry = 0;
            
//             for(int j = n2-1;j>=0;j--){
//                 int b = num2[j]-'0';
//                 int reminder = (a*b+carry)%10;
//                 carry = (a*b+carry)/10;
//                 tmp += reminder+'0';
                
//             }
//             if(carry!=0){
//                 tmp+=carry+'0';
//             }
//             reverse(tmp.begin(),tmp.end());
            
//             sum = add(sum+'0', tmp);
//         }
//         return sum;
//     }
//     string add(string num1, string num2){
//         int i=num1.size()-1;
//         int j = num2.size()-1;
//         int carry = 0;
//         string result;
//         while(i>=0 && j>=0){
//             int tmp = num1[i]-'0'+num2[j]-'0'+carry;
//             int reminder = tmp%10;
//             carry = tmp/10;
//             result += reminder+'0';
//             i--;
//             j--;
//         }
//         while(i>=0){
//             int tmp = num1[i]-'0'+carry;
//             int reminder = tmp%10;
//             carry = tmp/10;
//             result += reminder+'0';
//             i--;
//         }
//         while(j>=0){
//             int tmp = num2[j]-'0'+carry;
//             int reminder = tmp%10;
//             carry = tmp/10;
//             result += reminder+'0';
//             j--;
//         }
//         if(carry>0){
//             result += carry+'0';
//         }
//         reverse(result.begin(),result.end());
//         if(result[0]=='0') return "0";
//         return result;
//     }
// };