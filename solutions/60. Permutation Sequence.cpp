60. Permutation Sequence
class Solution {
public:
    string getPermutation(int n, int k) {
        int fraction[] = {1,1,2,6,24,120,720,5040,40320,362880};
        string init = "";
        if(k<=fraction[n-1]){
            for(int i = 1;i<=n;i++){
                init += i+'0';
            }
            for(int i = 0;i<k-1;i++){
                init = nextPermutation(init);
            }
            return init;
        }
        else{
            int first = k/fraction[n-1];
            int cnt = k%fraction[n-1];
            // cout<<first<<" "<<cnt<<endl;
            if(cnt != 0){
                first += 1;
            }
            else{
                cnt = fraction[n-1];
            }
            init += first+'0';
            for(int  i = 1;i<=n;i++){
                if(i==first){
                    continue;
                }
                else{
                    init += i+'0';
                }
            }
            for(int i =0;i<cnt-1;i++){
                init = nextPermutation(init);
            }
            return init;
        }
    }
    string nextPermutation(string str){
        // cout<<str<<endl;
        int size = str.length();
        int index_low = -1;
        for(int i=size-2;i>=0;i--){
            // cout<<i<<" str[i]:"<<str[i]<<" str[i+1]:"<<str[i+1]<<endl;
            if(str[i]<str[i+1]){
                index_low = i;
                break;
            }
        }
        // cout<<index_low<<" "<<str[index_low]<<endl;
        
        int index_high = -1;
        for(int i=size-1;i>=0;i--){
            if(str[i]>str[index_low]){
                index_high = i;
                // cout<<str[index_high]<<endl;
                char temp;
                temp = str[index_high];
                str[index_high] = str[index_low];
                str[index_low] = temp;
                reverse(str.begin()+index_low+1,str.end());

                break;
            }
        }
        return str;
        
        
    }
};