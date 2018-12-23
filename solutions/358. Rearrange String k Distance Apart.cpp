358. Rearrange String k Distance Apart
class Solution {
public:
    /*
    find frequency of char
    use max heap to pick char with max frequency
    */
    class Comparator{
    public:
        bool operator()(const pair<char,int>& a, const pair<char,int>& b){
            if(a.second!=b.second){
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        }  
    };
    string rearrangeString(string s, int k) {
        // check empty
        if(s.size()==0){
            return "";
        }
        if(k==0){
            return s;
        }
        // find frequency of char
        unordered_map<char, int> dict;
        int max_fre = 0;
        for(char c:s){
            dict[c]++;
            max_fre = max(max_fre, dict[c]);
        }
        // if(max_fre > (s.size()+1)/2) {
        //     return "";
        // }
        // use max heap to pick char with max frequency
        priority_queue<pair<char,int>, vector<pair<char,int>>, Comparator> pq;
        for(auto item:dict){
            pq.push(item);
        }
        string res;
        while(!pq.empty()){
            vector<pair<char,int>> temp;
            for(int i=0;i<k;i++){
                if(!pq.empty()){
                    pair<char,int> cur = pq.top();
                    pq.pop();
                    res += cur.first;
                    cur.second--;
                    if(cur.second>0){
                        temp.push_back(cur);
                    }
                } else {
                    if(temp.size()!=0){
                        return "";
                    }
                    break;
                }
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
        }
        return res;
    }

};