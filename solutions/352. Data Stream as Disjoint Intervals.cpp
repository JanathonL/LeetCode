352. Data Stream as Disjoint Intervals
使用vector存数据，然后每次都用二分查找low_bound和upper_bound进行更新。
如果merge比较多的话可以使用set做，set是使用bst实现的，插入查找都是logn。删除也比较方便
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        auto newInterval=Interval(val,val);
        auto cmp=[](Interval a, Interval b){return a.end+1 < b.start;};
        auto it0= lower_bound(intervals.begin(), intervals.end(),newInterval,cmp);
        auto it1= upper_bound(intervals.begin(), intervals.end(),newInterval,cmp);
       
        if(it0<it1){
            newInterval.start = min(newInterval.start, (*it0).start);
            newInterval.end = max(newInterval.end, (*(it1 - 1)).end);
            intervals.erase(it0,it1);
        }        
      
        intervals.insert(it0,newInterval);        
        
    }
    
    vector<Interval> getIntervals() { 
        return intervals;
    }

    
    private:
    vector<Interval> intervals;
    
    
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
// class SummaryRanges {
// public:
//     /** Initialize your data structure here. */
//     SummaryRanges() {
        
//     }
    
//     void addNum(int val) {
//         unordered_map<int,int>::iterator pre=m.end();
//         unordered_map<int,int>::iterator cur=m.end();
//         for(auto it=m.begin();it!=m.end();it++){
//             if(val>=it->first&& val<=it->second){
//                 return ;
//             }
//             else if(it->second+1==val){
//                 pre=it;
//             }
//             else if(it->first-1==val){
//                 cur=it;
//             }
//         }
//         // cout<<val<<endl;
//         if(pre!=m.end()&&cur!=m.end()){
//             // cout<<"c1"<<endl;
//             m[pre->first]=cur->second;
//             m.erase(cur->first);
//         }
//         else if(pre!=m.end()){
//             // cout<<"c2"<<endl;
//             m[pre->first]=val;
//         }
//         else if(cur!=m.end()){
//             // cout<<"c3"<<endl;
//             m[val]=cur->second;
//             m.erase(cur->first);
//         }
//         else{
//             // cout<<"c4"<<endl;
//             m[val]=val;
//         }
//     }
//     static bool cmp(Interval a, Interval b){
//         return a.start<b.start;
//     }
//     vector<Interval> getIntervals() {
//         vector<Interval> ans;
//         for(auto item:m){
//             ans.push_back(Interval(item.first,item.second));
//         }
//         sort(ans.begin(),ans.end(),cmp);
//         return ans;
//     }
// private:
//     unordered_map<int,int> m;
    
// };

// /**
//  * Your SummaryRanges object will be instantiated and called as such:
//  * SummaryRanges obj = new SummaryRanges();
//  * obj.addNum(val);
//  * vector<Interval> param_2 = obj.getIntervals();
//  */