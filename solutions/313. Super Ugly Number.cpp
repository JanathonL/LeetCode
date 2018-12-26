313. Super Ugly Number
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> p(primes.size(),0);
        int cnt=1;
        int ans = 0;
        vector<int> result(1,1);
        while(cnt<n){
            int minnum=INT_MAX;
            for(int i =0;i<primes.size();i++){
                minnum = min(result[p[i]]*primes[i],minnum);
            }
            result.push_back(minnum);
            for(int i =0;i<primes.size();i++){
                if(result.back()==result[p[i]]*primes[i]) p[i]++;
            }
            cnt++;                    
        }
        return result.back();
    }
};
