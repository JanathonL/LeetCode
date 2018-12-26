739. Daily Temperatures
/*
temp = [73, 74, 75, 71, 76, 73]
s = {(73,0),(74,1),(75,2),(76,4)}
res = {0,0,1,2,1,1}
res_reverse = {1,1,2,1,0,0}
time complexity : O(n)
space complexity : O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> s;
        vector<int> res;
        for(int i=t.size()-1;i>=0;i--){
            while(!s.empty()){
                int num = s.top().first;
                int index = s.top().second;
                if(num<=t[i]){
                    s.pop();
                }
                else{
                    s.push(make_pair(t[i],i));
                    res.push_back(index-i);
                    break;
                }

            }
            if(s.empty()){
                res.push_back(0);
                s.push(make_pair(t[i],i));
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};