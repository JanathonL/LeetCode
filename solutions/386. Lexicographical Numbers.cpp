// 386. Lexicographical Numbers
// 思路就是先要找一下数
// 三种条件
// 优先是cur*10  if cur*10<=n
// 其次是 cur += 1 if cur+1 <=n && cur%10!=9
// 之后是
// 		while((cur/10)%10!=9) cur/=10;
// 		cur = cur/10 + 1;
// 第三种情况是这样的， n = 600  cur=499的时候   下一个数应该是 5

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