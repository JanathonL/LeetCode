207. Course Schedule
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