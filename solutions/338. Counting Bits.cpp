338. Counting Bits
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        if(num==0) {
            return ans;
        }
        int ind=0;
        int i=1;
        while(i<=num){
            if(i>=int(pow(2,ind))&&i<int(pow(2,ind+1))){
                ans[i]=ans[i-int(pow(2,ind))]+1;
                i++;
            }
            else{
                ind++;
            }
        }
        return ans;
    }
};