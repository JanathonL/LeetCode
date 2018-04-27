// 332. Reconstruct Itinerary
// DFS，先对ticket排序，之后只要第一次找到结果就可以return了,使用一个cnt来计数，只要是满足了cnt==ticket.size()就是找到结果了
// 但是不知道为什么，用
// unordered_map<string,vector<string>> map;
// for(auto it:map){
// 		sort(it.second.begin(),it.second.end());
// }
// 并不能真的吧map里第二项vector<string> 排好序。
// 查了一下资料发现：
// auto it:map 这里的it应该是一个新的元素，直接是按照map的元素，拷贝的，所以sort并不是在原来的数组上的。 
// 可以写成auto it=map.begin();it!=map.end();it++,这样就是指针形式，可以sort(it->second.begin(),it->second.end())； 可以改变原来map中的vector。
class Solution {
public:
    static bool cmp(pair<string,string> a, pair<string,string> b){
        if(a.first!=b.first){
            return a<b;
        }
        else{
            return a.second<b.second;
        }
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> l;
        cnt=0;
        unordered_map<string, vector<string>> after;
        // sort(tickets.begin(),tickets.end(),cmp);
        for(int i=0;i<tickets.size();i++){
            after[tickets[i].first].push_back(tickets[i].second);
        }
        for(auto it=after.begin();it!=after.end();it++){
            sort(it->second.begin(),it->second.end());
        }
        for(int i=0;i<after["JFK"].size();i++){
            cout<<after["JFK"][i]<<" ";
        }
        cout<<endl;
        res.push_back("JFK");
        dfs(tickets,after,"JFK");
        return res;
        
        
        
    }
    void dfs(vector<pair<string, string>>& tickets,  
             unordered_map<string, vector<string>>& after, string cur){
        
        if(after.find(cur)==after.end()) return ;
        
        
        
        
        
        for(int i=0;i<after[cur].size();i++){
            string tmp = after[cur][i];
            
            res.push_back(tmp);
            
            auto pos = after[cur].begin()+i;
            after[cur].erase(pos);
            cnt++;
            // cout<<i<<" "<<tmp<<endl;
            dfs(tickets,after,tmp);
            if(cnt==tickets.size()){
                // cout<<"true"<<endl;
                return ;
            }
            cnt--;
            after[cur].insert(pos,tmp);
            res.pop_back();
        }
        
        
        
    }
    vector<string> cmp_assign(vector<string> res, vector<string> l){
        if(res.size()==0) return l;
        for(int i=0;i<res.size();i++){
            if(res[i]>l[i]){
                return l;
            }
            else if(res[i]<l[i]){
                return res;
            }
        }
        return l;
    }
    vector<string> res;
    int cnt;
};