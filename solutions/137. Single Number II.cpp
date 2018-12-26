137. Single Number II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> dict(32,0);
        for(int n:nums){
            set_dict(n, dict);
        }
        return construct(dict);
    }
    void set_dict(int n, vector<int>& dict){
        unsigned mask = 1;
        for(int i=0;i<32;i++){
            if((n&mask) != 0){  // 这个地方要加括号, 还要用不等于0
                dict[i]++;
            }
            mask <<= 1;
        }
    }
    int construct(vector<int> dict){
        int mask = 1;
        int sum = 0;
        for(int i=0;i<dict.size();i++){
            if(dict[i]%3==1){
                sum += mask;
            }
            mask <<= 1;
        }
        return sum;
    }
};