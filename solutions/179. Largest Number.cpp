179. Largest Number
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i =0;i<nums.size();i++){
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(),strs.end(),cmp);
        string ans;
        for(int i =0;i<strs.size();i++){
            ans += strs[i];
        }
        
        return ans[0]=='0'? "0":ans;
    }
    static bool cmp(string a,string b){
        return (a+b)>(b+a);
    }
    
};