547. Friend Circles
class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void connect(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        parent[x] = y;
    }
    int findCircleNum(vector<vector<int>>& M) {
        parent.resize(M.size(),0);
        for(int i=0;i<M.size();i++){
            parent[i] = i;
        }
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]==1){
                    connect(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<M.size();i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};