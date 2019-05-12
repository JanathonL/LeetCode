900. RLE Iterator
// refined beat 40%
class RLEIterator {
public:
    // comulative array
    // binary search
    
    vector<long> ind;
    unordered_map<long, int> dict;
    long cur;
    // O(N)
    RLEIterator(vector<int>& A) {
        cur = 0;
        long cnt = 0;
        for(int i=0;i<A.size();i+=2){
            int times = A[i];
            int num = A[i+1];
            if(times!=0){
                cnt += times;
                ind.push_back(cnt);
                dict[cnt] = num;
            } else {
                continue;
            }
        }
    }
    // log(N)
    long bs(long n){
        if(n>ind.back()){
            return -1;
        }
        long lo = 0;
        long hi = ind.size()-1;
        while(lo<hi){
            long mid = lo + (hi-lo)/2;
            if(ind[mid]>=n){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
    
    int next(int n) {
        cur += n;
        long pos = bs(cur);
        if(pos>=0){
            return dict[ind[pos]];
        } else {
            return -1;
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */