207. Course Schedule
// refined
// beat 46.52%
// time: O(N)
// space: O(N)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& pres) {
        unordered_map<int,int> indeg;
        unordered_map<int,vector<int>> neighbs;
        for(int i=0;i<numCourses;i++){
            indeg[i] = 0;
        }
        for(int i=0;i<pres.size();i++){
            pair<int,int> pre = pres[i];
            indeg[pre.first]++;
            neighbs[pre.second].push_back(pre.first);
        }
        queue<int> que;
        for(auto item:indeg){
            if(item.second==0){
                que.push(item.first);
            }
        }
        int cnt = 0;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            cnt ++;
            for(auto nei:neighbs[cur]){
                indeg[nei]--;
                if(indeg[nei]==0){
                    que.push(nei);
                }
            }
        }
        return cnt==numCourses;
    }
};