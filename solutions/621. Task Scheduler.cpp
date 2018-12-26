class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt = 0;
        unordered_map<int,int> dict;
        int max_len = 0;
        for(char c:tasks){
            dict[c]++;
            max_len = max(max_len, dict[c]);
        }
        int res = (n+1)*(max_len-1);
        for(auto item:dict){
            if(item.second==max_len){
                res++;
            }
        }
        return max(res, int(tasks.size()));
    }
    /*
    24 min
    7 wrong
    time: O(NlogN)
    space: O(N)
    */
    // class Comparator{
    // public:  // 一定要注意用public!!!!!
    //     bool operator()(const pair<char,int>& a, const pair<char,int>& b){
    //         return a.second < b.second;
    //     }  
    // };
    // int leastInterval(vector<char>& tasks, int n) {
    //     vector<pair<char,int>> temp;
    //     priority_queue<pair<char, int>, vector<pair<char,int>>, Comparator> pq;
    //     unordered_map<char,int> dict;
    //     for(int i=0;i<tasks.size();i++){
    //         dict[tasks[i]]++;
    //     }
    //     for(auto item:dict){
    //         pq.push(item);
    //     }
    //     int res = 0;
    //     while(!pq.empty()){
    //         for(int i=0;i<=n;i++){  // 看清题目，间隔其实是要n+1
    //             if(pq.empty()){  // 一定要判断 pq空不空
    //                 if(temp.size()!=0){  // 判断还有没有等待的任务
    //                     // idle
    //                     res++;
    //                     continue;
    //                 } else {
    //                     break;
    //                 }
    //             } 
    //             pair<char,int> cur = pq.top();
    //             pq.pop();
    //             res++;
    //             cur.second --;
    //             if(cur.second>0){
    //                 temp.push_back(cur);
    //             }
    //         }
    //         for(int i=0;i<temp.size();i++){
    //             pq.push(temp[i]);
    //         }
    //         temp.clear();
    //     }
    //     return res;
    // }
};