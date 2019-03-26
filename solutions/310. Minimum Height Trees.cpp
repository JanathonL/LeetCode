310. Minimum Height Trees
class Solution {
public:
    class Node{
    public:
        unordered_set<int> neighbors;
        bool is_leaf(){return neighbors.size()==1;}
    };
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<Node> node(n);
        for(int i=0;i<edges.size();i++){
            node[edges[i].first].neighbors.insert(edges[i].second);
            node[edges[i].second].neighbors.insert(edges[i].first);
        }
        vector<int> b1;
        vector<int> b2;
        if(n==1){
            b1.push_back(0);
            return b1;
        }
        if(n==2){
            b1.push_back(0);
            b1.push_back(1);
            return b1;
        }
        for(int i=0;i<n;i++){
            if(node[i].is_leaf()){
                b1.push_back(i);
            }
        }
        while(1){
            for(auto i:b1){
                for(auto item:node[i].neighbors){
                    node[item].neighbors.erase(i);
                    if(node[item].is_leaf()){
                        b2.push_back(item);
                    }
                }
            }
            if(b2.size()==0) return b1;
            b1.clear();
            swap(b1,b2);
        }
    }
};



310. Minimum Height Trees
/*
check cycles
在一副可以形成树的图中，满足题目要求的结点个数只能为2，1或者0，当结点个数为0时，
满足题目要求的结点个数也为0。现在假设存在三个结点满足题目要求，那么这三个结点为根的树的高度都是相同的，
并且由于此图中每两个结点都有唯一一条路径相通，那么这这三个结点可以由一条路径相连，
假设以位于中间的那个结点为根的树的高度为n，那么在另外两个结点中必然有一个结点满足其为根的树的最大高度为n+distance(中间的结点，此结点)，
这样子，该结点就不再满足题目的要求。所以满足要求的结点个数只能为1或者2（总结点个数不为0）。
那么现在想要求这两个点或者一个点，以此结点为根的树的高度是最小的，树的高度是由距离根结点最远的叶结点决定的，
我们找到在图中距离最远的两个叶结点，那么这两个结点E，F的中间一个A或者两个结点A，B就是题目所求。因为无论哪一点到达E和F的最大值都要大于A和B。
那么存不存在某个叶结点G到A或者B的距离大于A和B达到E，F的距离呢，当然不存在这样点，否则的话EF就不是整个图中相距最远的两个叶结点了。
从最底层的叶结点开始，一层一层地往上删除，最终剩下的一个或者两个结点就是要求的点。

refined: beat 16%
time: O(VE)
space: O(VE)
*/
class Solution {
public:
    vector<int> delete_leaves(int n, unordered_map<int, unordered_set<int>> neighbors){
        queue<int> que;
        for(int i=0;i<n;i++){
            if(neighbors[i].size()<=1){
                que.push(i);
            }
        }
        int cnt = n;
        while(!que.empty() && cnt>2){
            int size = que.size();
            cnt -= size;
            for(int i=0;i<size;i++){
                int cur = que.front();
                que.pop();
                for(int nei:neighbors[cur]){
                    neighbors[nei].erase(cur);
                    if(neighbors[nei].size()==1) que.push(nei);
                }
                neighbors[cur].clear();
            }
        }
        vector<int> res;
        while(!que.empty()){
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        // init
        unordered_map<int, unordered_set<int>> neighbors;
        for(pair<int,int> edge:edges){
            neighbors[edge.first].insert(edge.second);
            neighbors[edge.second].insert(edge.first);
        }
        int min_len = n;
        return delete_leaves(n, neighbors);
    }
};