vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    unordered_map<int, vector<int>> neigh;
    queue<int> que;
    for(pair<int,int> pre : prerequisites){
        indegree[pre.first]++;
        neigh[pre.second].push_back(pre.first);
    }
    for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }
    vector<int> res;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        res.push_back(cur);
        for(int nei:neigh[cur]){
            indegree[nei]--;
            if(indegree[nei]==0){  // 注意要写indegree啊！！
                que.push(nei);
            }
        }
    }
    if(res.size()==numCourses){  // 判断有没有环
        return res;
    } else {
        return {};
    }
}