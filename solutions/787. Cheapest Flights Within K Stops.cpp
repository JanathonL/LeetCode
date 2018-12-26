787. Cheapest Flights Within K Stops
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        if(K>n) K = n-1;
        for(int i=0;i<K+1;i++){
            vector<int> c(dist);
            for(int j=0;j<flights.size();j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];
                if(dist[s]!=INT_MAX && dist[s]+w < c[d]){
                    c[d] = dist[s]+w;
                }
            }
            dist = c;
        }
        return dist[dst]==INT_MAX? -1:dist[dst];
        
    }
};