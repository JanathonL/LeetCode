// 207. Course Schedule
// 拓扑排序
// 先把所有节点的indegree算出来，还有所有节点的后续节点算出来after.
// 遍历indegree数组把所有indegree为0的节点压到stack s中，
// 之后pop出来的节点i， 存到vector L中顺序保存，
// 然后去把所有的后序节点after的indegree都减一，如果indegree==0，也压入，把这条边删除（cnt--）,最后判断图中还有没有边。

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
        int cnt = pre.size();
        if(cnt==0) return true;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> after(numCourses,vector<int>());
        for(int i=0;i<pre.size();i++){
            indegree[pre[i].second]++;
            after[pre[i].first].push_back(pre[i].second);
            // cout<<pre[i].second<<endl;
        }
        stack<int> s;
        for(int i=0;i<indegree.size();i++){
            if(0==indegree[i]) s.push(i);
        }
        while(!s.empty()){
            int i = s.top();
            s.pop();
            for(auto w:after[i]){
                // cout<<w<<endl;
                cnt--;
                indegree[w]--;
                if(0==indegree[w]){
                    s.push(w);
                }
            }
        }
        // cout<<cnt<<endl;
        if(0==cnt){
            return true;
        }
        return false;
        
    }
};