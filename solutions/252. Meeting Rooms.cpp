252. Meeting Rooms
// refined
// beat 45%
// time: O(N)
// space: O(1)
class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i=1;i<intervals.size();i++){
            Interval pre = intervals[i-1];
            Interval cur = intervals[i];
            if(pre.end>cur.start){
                return false;
            }
        }
        return true;
    }
};