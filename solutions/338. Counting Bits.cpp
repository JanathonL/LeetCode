// 338. Counting Bits
// DP： Time O(n) 
// 0->0 0
// 1->0 1
// 2->1 0
// 3->1 1
// 可以看到2和3和0,1相比就多了最高位的1，其余都是和0，1一样，这就可以发现一个dp规律
// if(i>=2^ind && i< 2^(ind+1)) x[i]=x[i-2^ind]+1;  比如x[2]=x[2-2]+1=0+1=1
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