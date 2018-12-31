306. Additive Number
class Solution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
            string sum = add(num1,num2);
            if(sum==num) return true;
            if(sum.size()>=num.size()|| sum.compare(num.substr(0,sum.size()))!=0) return false;
            return check(num2,sum,num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
    };



// first iterator first 2 numbers
// use string add to avoid overflow
// refined 
// beat 100%
// time: O()
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        for(int i=1;i<=num.size()/2;i++){
            for(int j=1;j<=num.size()/2;j++){
                if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))){
                    return true;
                }
            }
        }
        return false;
    }
    bool check(string first, string second, string third){
        // cout<<first<<" "<<second<<" "<<third<<endl;
        if(first.size()>1&&first[0]=='0' || second.size()>1&&second[0]=='0'){
            return false;
        }
        string sum = add(first, second);
        // cout<<"sum:"<<sum<<endl;
        if(sum==third){
            return true;
        } else {
            if(sum.size()>third.size() || sum!=third.substr(0,sum.size())){
                return false;
            } else {
                return check(second, sum, third.substr(sum.size()));
            }
        }
    }
    string add(string first, string second){
        int carry = 0;
        int i = first.size()-1, j = second.size()-1;
        string res;
        while(i>=0 || j>=0 || carry){
            int temp = 0;
            if(i>=0){
                temp += first[i]-'0';
                i--;
            }
            if(j>=0){
                temp += second[j]-'0';
                j--;
            }
            temp += carry;
            res += (temp%10)+'0';
            carry = temp/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};