825. Friends Of Appropriate Ages'
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        sort(ages.begin(),ages.end());
        for(int i=0;i<ages.size();i++){
            auto same = lower_bound(ages.begin(),ages.end(),ages[i]);
            auto up = upper_bound(ages.begin(),ages.end(),ages[i]*0.5+7);
            if(up-ages.begin()<i) {//a>= b >a*0.5+7
                ans += i-(same-ages.begin());
                ans += i-(up-ages.begin());
            }
        }
        return ans;
    }
};