786. K-th Smallest Prime Fraction
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double lo = 0;
        double hi = 1;
        vector<int> ans(2,0);
        while(hi-lo > 1e-9){
            double mid = lo+(hi-lo)/2.0;
            vector<int> res = under(A,mid);
            if(res[0]>K){
                hi = mid;
            } else {
                ans[0] = res[1];
                ans[1] = res[2];
                lo = mid;
            }
        }
        return ans;
    }
    vector<int> under(vector<int> primes, double target){
        int j=-1;
        int cnt = 0;
        int molecule = 0;
        int denominator = 1;
        for(int i=0;i<primes.size();i++){
            while(primes[j+1]*1.0 <= target*primes[i]) j++;
            cnt += j+1;
            if(j>=0 && primes[j]*denominator > primes[i]*molecule){
                denominator = primes[i];
                molecule = primes[j];
            }
        }
        return {cnt, molecule, denominator};
    }
};