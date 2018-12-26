386. Lexicographical Numbers
class Solution {
public:
    static bool cmp(int a, int b){
        return to_string(a)<to_string(b);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for(int i=0;i<n;i++){
            res[i]=cur;
            if(cur*10<=n){
                cur*=10;
            }
            else if(cur%10 !=9 && cur+1 <=n){
                cur ++;
            }
            else{
                while((cur/10)%10==9){
                    cur /=10;
                }
                cur = cur/10+1;
            }
        }
        return res;
    }
    void put_nums(vector<int> nums, string name){
        cout<<name<<": ";
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};