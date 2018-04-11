// 202. Happy Number
// 只要右边的数不要重复就可以了，一旦有重复就return false
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        vector<int> digits = getdigits(n);
        int sum = n;
        while(m.find(sum)==m.end()){
            m.insert(sum);
            sum = getsum(digits);
            // cout<<"sum:"<<sum<<endl;
            if(sum == 1){
                return 1;
            }
            else{
                digits = getdigits(sum);
            }
            
        }
        return 0;
    }
    
    vector<int> getdigits(int n){
        vector<int> digits;
        if(n==0) {
            digits = {0};
            return digits;
        }
           
        while(n!=0){
            digits.push_back(n%10);
            n /= 10;
        }
        return digits;
    }
    int getsum(vector<int> digits){
        int sum = 0;
        for(int i =0;i<digits.size();i++){
            sum += digits[i]*digits[i];
        }
        return sum;
    }
    
};