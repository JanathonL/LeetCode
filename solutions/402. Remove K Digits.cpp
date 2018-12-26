402. Remove K Digits
class Solution {
public:
    string deletezero(string str){
        int start;
        for(start = 0;start<str.size();start++){
            if(str[start]!='0'){
                break;
            }
        }
        if(start!=str.size())
            return str.substr(start);
        else{
            return "0";
        }
    }
    string removeKdigits(string num, int k) {
        int len = num.size();
        if(k>=len) return "0";
        string res = "";
        int start=0;
        while(k>0){
            int ind = -1;
            char c = '9'+1;
            for(int i=start;i<start+k+1;i++){
                if(c>num[i]){
                    ind = i;
                    c = num[i];
                    // cout<<c<<endl;
                }
            }
            res += c;
            k  -= ind -start;
            start = ind+1;
            if(len - start ==k){
                break;
            }
        }
        if(k!=0){
            return deletezero(res);
        }
        else{
            res += num.substr(start);
            return deletezero(res);
        }
    }
};
