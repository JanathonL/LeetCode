class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
        if (ins.empty()) return vector<Interval>{};
        vector<Interval> res;
        sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
        res.push_back(ins[0]);
        for (int i = 1; i < ins.size(); i++) {
            if (res.back().end < ins[i].start) res.push_back(ins[i]);
            else
                res.back().end = max(res.back().end, ins[i].end);
        }
        return res;
    }
};
// /**
//  * Definition for an interval.
//  * struct Interval {
//  *     int start;
//  *     int end;
//  *     Interval() : start(0), end(0) {}
//  *     Interval(int s, int e) : start(s), end(e) {}
//  * };
//  */
// class Solution {
// public:
//     vector<Interval> merge(vector<Interval>& intervals) {
//         vector<Interval> result;
//         if(intervals.size()<=1) return intervals;
//         result.push_back(intervals[0]);
//         for(int i =1;i<intervals.size();i++){
//             result=mergeone(result,intervals[i]);
//         }
//         return result;
//     }
//     vector<Interval> mergeone(vector<Interval>& inter, Interval newI){
//         int n = inter.size();
//         int i =0;
//         vector<Interval> result;
//         while(i<n&&inter[i].end<newI.start){
//             result.push_back(inter[i++]);
//         }
//         while(i<n&&inter[i].start<=newI.end){
//             newI = Interval(min(newI.start,inter[i].start),max(newI.end,inter[i].end));
//             i++;
//         }
//         result.push_back(newI);
//         while(i<n){
//             result.push_back(inter[i++]);
//         }
//         return result;
//     }
    
// };
