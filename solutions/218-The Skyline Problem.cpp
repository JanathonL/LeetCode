// 218. The Skyline Problem
// 思路是用一个vector把每个corner点的坐标存起来，
// 开头的点height用正的，结尾的点，height用负的，  比如开头的点：b[0],b[2]， 结尾的点： b[1],-b[2]。然后把这个东西排序一下，保证从左到右扫描。
// 先碰到开头的节点，那就把这个加入到multiset中（multiset可以快速找到最大的节点*mset.rbegin()，插入操作是logn），
// 如果碰到一个房子的结尾了，（height<0）那就把房子开头的节点用multiset找到然后删除。每次都去找最大的cur，把h.first,cur加入到res中去。
// 这样做的好处是，每次都能保证找到最高的点作为corner，而且当到达一个结尾的时候可以判断这个时候是否是corner结尾。
// trick就是，先在multiset中加入0，这样可以保证到达一个房子最末尾的时候，就可以把h.first,0插进去

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> heights;
        for(auto b:buildings){
            heights.push_back({b[0],-b[2]});
            heights.push_back({b[1],b[2]});
        }
        sort(heights.begin(),heights.end(),cmp);
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
    static bool cmp(pair<int,int> a, pair<int,int> b){ return a.first<b.first;}
};