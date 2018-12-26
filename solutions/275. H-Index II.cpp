275. H-Index II
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int first = 0, last = citations.size();
        int len = citations.size();
        while(first!=last){
            int mid = (first+last)/2;
            if(citations[mid]==len-mid) return len-mid;
            if(citations[mid]>len-mid) {
                last = mid;
            }
            else{
                first = mid + 1;
            }
        }
        return len - first;
    }
};