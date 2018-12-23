57. Insert Interval
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
insert intervals ends before new interval
merge 
insert intervals start after merged interval
8 min
bug free!!
time: O(n)
space: O(1)
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        vector<Interval> res;
        for(;i<intervals.size();i++){
            if(intervals[i].end<newInterval.start){
                res.push_back(intervals[i]);
            } else {
                break;
            }
        }
        for(;i<intervals.size();i++){
            if(intervals[i].start<=newInterval.end){
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                break;
            }
        }
        res.push_back(newInterval);
        for(;i<intervals.size();i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};