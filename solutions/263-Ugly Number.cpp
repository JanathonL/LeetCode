// 263. Ugly Number
// 开头判断一下0是false, 1是true. 除完2,3,5然后判断一下一下剩余的是不是1，如果是1就true,否则就false
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        if(num==1 ) return true;
        while(num%2==0){
            num/=2;
        }
        while(num%3==0){
            num/=3;
        }
        while(num%5==0){
            num/=5;
        }
        if(num==1) return true;
        else return false;
    }
};