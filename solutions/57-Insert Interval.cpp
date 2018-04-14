
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& inter, Interval newI) {
        int left = 0;
        int right = 0;
        int n = inter.size();
        int i=0;
        vector<Interval> result;
        while(i<n&&inter[i].end<newI.start) {
            result.push_back(inter[i++]);
        }
        
        while(i<n&&inter[i].start<=newI.end){
            newI = Interval(min(newI.start,inter[i].start),max(newI.end,inter[i].end));
            i++;
        }
        result.push_back(newI);
        while(i<n){
            result.push_back(inter[i++]);
        }
        return result;
            
            
            
        
    }
};
