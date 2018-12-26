218. The Skyline Problem
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> heights;
        for(auto b:buildings){
            heights.push_back({b[0],-b[2]});
            heights.push_back({b[1],b[2]});
        }
        sort(heights.begin(),heights.end());
        int prev=0,cur;
        multiset<int> mset {0};
        vector<pair<int,int>> res;
        for (pair<int,int> h:heights) {
            if (h.second<0) mset.insert(-h.second);
            else mset.erase(mset.find(h.second));
            
            cur=*mset.rbegin();
            if (prev!=cur) {
                res.push_back({h.first,cur});
                prev=cur;
            }
        }
        return res;
    }
};