228. Summary Ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        if(a.size()==0) return vector<string>();
        int start=a[0];
        int end = a[0];
        
        vector<string> res;
        a.push_back(INT_MAX);
        for(int i=0;i<a.size()-1;i++){
            if(a[i+1]==a[i]+1){
                end=a[i];
            }
            else{
                end=a[i];
                if(end==start){
                    string tmp;
                    tmp += to_string(start);
                    res.push_back(tmp);
                }
                else{
                    string tmp;
                    tmp += to_string(start);
                    tmp += "->";
                    tmp += to_string(end);
                    res.push_back(tmp);
                }
                start=a[i+1];
                end=a[i+1];
            }
        }
        return res;
    }
};