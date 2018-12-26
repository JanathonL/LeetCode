// 56. Merge Intervals
// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
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
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(),intervals.end(),cmp);
        Interval pre = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<=pre.end){
                pre.end = max(intervals[i].end,pre.end);
            }
            else{
                res.push_back(pre);
                pre = intervals[i];
            }
        }
        res.push_back(pre);
        return res;
    }
};