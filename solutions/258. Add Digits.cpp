// 258. Add Digits
// 正常模拟就好了，无trick
class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            num = cal(num);
        }
        return num;
    }
    int cal(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};