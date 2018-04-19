// 210. Course Schedule II
// 和之前的拓扑排序一样的思路，不过是多了一个vector<int> L，每次stack栈顶pop出元素的时候存入L中。

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<int> L;
        stack<int> s;
        int edge = pre.size();
        vector<int> indegree(numCourses,0);
        vector<vector<int>> after(numCourses, vector<int>());
        for(int i=0;i<pre.size();i++){
            indegree[pre[i].first]++;
            after[pre[i].second].push_back(pre[i].first);
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                s.push(i);
            }
        }
        while(!s.empty()){
            int i = s.top();
            L.push_back(i);
            s.pop();
            for( auto w: after[i]){
                edge--;
                indegree[w]--;
                if(0==indegree[w]){
                    s.push(w);
                }
            }
        }
        if(0==edge){
            return L;
        }
        return vector<int>();
        
        
    }
};