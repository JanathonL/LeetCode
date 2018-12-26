274. H-Index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> m(citations.size()+1);
        int n = citations.size();
        for(int i =0;i<n;i++){
            if(citations[i]>n){
                for(int j =0 ;j<=n;j++){
                    m[j]++;
                }
            }
            else{
                for(int j =0 ;j<=citations[i];j++){
                    m[j]++;
                }
            }
        }
        int i =0;
        for(i =n;i>=0;i--){
            if(m[i]>=i){
                return i;
            }
        }
        return 0;
    }
};