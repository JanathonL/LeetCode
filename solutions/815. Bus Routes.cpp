815. Bus Routes
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& rt, int S, int T) {
        if (S==T) return 0;
        unordered_map<int,unordered_set<int>> m;
        int n = rt.size();
        if(n==0) return -1;
        for(int i =0;i<n;i++){
            for(auto t:rt[i]){
                m[t].insert(i);
            }
            
        }
        vector<bool> vis(n+1, false);
        queue<int> q;
        q.push(S);
        unordered_map<int,int> d;
        d[S] = 0;
        while(!q.empty()){
            
            int now = q.front();
            q.pop();
            int dnow = d[now];
            // cout<<"now:"<<now<<" dnow:"<<dnow<<endl;
            for(auto next:m[now]){
                if(!vis[next]){
                    vis[next]=true;
                    for(auto stops : rt[next]){
                        if(d.find(stops)==d.end()){
                            d[stops]= dnow+1;
                            if(stops==T) return dnow+1;
                            q.push(stops);
                        }
                    }

                }
                
            }
        }
        return -1;
    }
};