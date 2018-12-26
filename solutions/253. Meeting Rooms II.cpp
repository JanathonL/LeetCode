253. Meeting Rooms II
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
    /*
    sort array
    use priority_queue min heap
    put end to heap
    if cur.start > heap.top(){
        pop
        push cur.end
    } else {
        push cur.end
    }
    return heap.size()
    
    9 min
    2 wrong
    time: O(NlogN)
    space: O(N)
    */
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);  // sort的时候一定要注意自己弄一个函数
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            Interval cur = intervals[i];  // 类型名是 Interval, 变量名是 intervals, 千万别弄错
            if(!pq.empty() && cur.start>=pq.top()){  // 要和面试官弄清楚 等于算不算 重叠
                pq.pop();
                pq.push(cur.end);
            } else {
                pq.push(cur.end);
            }
        }
        return pq.size();
    }
};