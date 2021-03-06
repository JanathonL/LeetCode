// 825. Friends Of Appropriate Ages
// 先排序，再用二分查找来做，Time: O(nlogn) 
// 可以使用内置的 upper_bound 表示先找到第一个大于这个数的位置
// lower_bound 表示找到第一个大于等于这个数的位置
//    lower            upper
// 0   1     1   1      4 
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