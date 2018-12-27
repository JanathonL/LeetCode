12. Integer to Roman
class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits;
        while(num!=0){
            digits.push_back(num%10);
            num/=10;
        }
        // reverse(digits.begin(),digits.end());
        string c1="IXCM";
        string c2="VLD";
        string ans = "";
        for(int i = digits.size()-1;i>=0;i--){
            if(digits[i]>=0&&digits[i]<=3){
                for(int j =0;j<digits[i];j++){
                    ans+=c1[i];
                }
            }
            else if(digits[i]==4 && i<3){
                ans+=c1[i];
                ans+=c2[i];
            }
            else if(digits[i]>=5 && digits[i]<9 && i<3){
                ans+=c2[i];
                for(int j=0;j<digits[i]-5;j++){
                    ans += c1[i];
                }
            }
            else if(digits[i]==9 && i<3){
                ans+=c1[i];
                ans+=c1[i+1];
            }
        }
        return ans;
    }
};

// refined
// beat 87.66%
// time: O(1)
// space: O(1)
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> dict;
        dict = {{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},
                {"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        int cur = 0;
        string res;
        while(num>0){
            if(num>=dict[cur].second){
                num -= dict[cur].second;
                res += dict[cur].first;
            } else {
                cur++;
            }
        }
        return res;
    }
};