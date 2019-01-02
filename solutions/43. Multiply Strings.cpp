// 43. Multiply Strings
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string prev;
        string zero;
        for(int i=num1.size()-1;i>=0;i--){
            string cur = multiply(num1[i],num2);
            
            // cout<<prev<<endl;
            cur += zero;
            zero+='0';
            
            prev = add(cur,prev);
        }
        string ans;
        int i;
        for(i=0;i<prev.size();i++){
            if(i==prev.size()-1 || prev[i]!='0') break;
        }
        ans = prev.substr(i);
        return ans==""?"0":ans;
    }
    string multiply(char c, string num){
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            int n1 = c-'0';
            int n2 = num[i]-'0';
            int res = n1*n2+carry;
            num[i] = (res%10)+'0';
            carry = res/10;
        }
        string ans;
        if(carry!=0){
            ans += carry+'0';
            ans += num;
        }
        else{
            ans = num;
        }
        return ans;
    }
    string add(string num1, string num2){
        int carry = 0;
        int i,j;
        i=num1.size()-1;
        j=num2.size()-1;
        string ans;
        while(i>=0&& j>=0){
            int res = num1[i]-'0' +num2[j]-'0'+carry;
            ans += (res%10)+'0';
            carry = res/10;
            i--;
            j--;
        }
        while(i>=0){
            int res = num1[i]-'0'+carry;
            ans += (res%10)+'0';
            carry = res/10;
            i--;
        }
        while(j>=0){
            int res = num2[j]-'0'+carry;
            ans += (res%10)+'0';
            carry = res/10;
            j--;
        }
        if(carry){
            ans += carry+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// refined
// beat: 69.90%
// time: O(nm)
// space: O(n+m)
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()==0 || num2.size()==0){
            return "0";
        }
        vector<int> temp(num1.size()+num2.size(),0);
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                temp[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        for(int i=temp.size()-1;i>=0;i--){
            temp[i] += carry;
            carry = temp[i]/10;
            temp[i] = temp[i]%10;
        }
        if(carry){
            temp[0] = carry;
        }
        int i = 0;
        for(i=0;i<temp.size();i++){
            if(temp[i]!=0||i==temp.size()-1) break;
        }
        string res;
        for(;i<temp.size();i++){
            res += temp[i]+'0';
        }
        return res;
    }
};