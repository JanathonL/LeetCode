332. Reconstruct Itinerary
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
        sort(tickets.begin(),tickets.end(),cmp);
        for(int i=0;i<tickets.size();i++){
            after[tickets[i].first].push_back(tickets[i].second);
        }
        // for(auto it:after){
        //     sort(it.second.begin(),it.second.end());
        //     // cout<<it.first<<" ";
        //     // for(auto str:it.second){
        //     //     cout<<str<<" ";
        //     // }
        //     // cout<<endl;
        // }
        // for(int i=0;i<after["JFK"].size();i++){
        //     cout<<after["JFK"][i]<<" ";
        // // }
        // cout<<endl;
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