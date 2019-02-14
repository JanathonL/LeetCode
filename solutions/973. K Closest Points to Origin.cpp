973. K Closest Points to Origin
// beat 11.90%
// time: O(Klogn)
// space: O(N)
class Solution {
public:
    class Comparator{
    public:
        bool operator()(pair<vector<int>,double> a, pair<vector<int>, double> b){
            return a.second>b.second;
        }    
    };
    double cal(vector<int> point){
        return point[0]*point[0]+point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<vector<int>,double>, vector<pair<vector<int>,double>>, Comparator> pq;
        for(vector<int> point:points){
            double dist = cal(point);
            pq.push({point, dist});
        }
        vector<vector<int>> res;
        while(!pq.empty()&&K>0){
            res.push_back(pq.top().first);
            K--;
            pq.pop();
        }
        return res;
    }
};

// beat 43.90%
// time: O(N)
// space: O(1)
class Solution {
public:
    double cal(vector<int> point){
        return point[0]*point[0]+point[1]*point[1];
    }
    int partition(vector<pair<vector<int>, double>>& dists, int low, int hi){
        double pivot = dists[low].second;
        int i = low, j = hi;
        while(i<j){
            if(pivot>=dists[j].second){
                i++;
                swap(dists[i],dists[j]);
            } else {
                j--;
            }
        }
        swap(dists[i],dists[low]);
        return i;
    }
    void qsort(vector<pair<vector<int>, double>>& dists, int k, int low, int hi){
        int ind = partition(dists, low, hi);
        if(ind>k-1) {
            qsort(dists, k, low, ind-1);
        } else if(ind<k-1){
            qsort(dists, k, ind+1, hi);
        } else {
            return;
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<vector<int>, double>> dists;
        for(vector<int> point:points){
            dists.push_back({point, cal(point)});
        }
        qsort(dists, K, 0, dists.size()-1);
        vector<vector<int>> res;
        for(int i=0;i<K && dists.size();i++){
            res.push_back(dists[i].first);
        }
        return res;
    }
};