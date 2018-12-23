269. Alien Dictionary
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size()==0){
            return "";
        } else if(words.size()==1){
            return words[0];
        }
        unordered_map<char, vector<char>> neighbs;  
        unordered_map<char, int> indegree;
        construct_graph(words, neighbs, indegree);
        string res = topo_sort(neighbs, indegree);
        return res;
    }
    string topo_sort(unordered_map<char, vector<char>>& neighbs, unordered_map<char, int>& indegree){
        queue<char> que;
        for(auto item : indegree){
            if(item.second == 0){
                // cout<<item.first<<endl;
                que.push(item.first);
            }
        }
        string res;
        while(!que.empty()){
            char cur = que.front();
            que.pop();
            res.push_back(cur);
            for(char neighb : neighbs[cur]){
                indegree[neighb]--;
                if(indegree[neighb]==0){
                    que.push(neighb);
                }
            }
        }
        // cout<<res<<endl;
        if(res.size()==indegree.size()){
            return res;
        } else {
            return "";
        }
    }
    void construct_graph(vector<string> words, unordered_map<char, vector<char>>& neighbs, unordered_map<char, int>& indegree){
        int n = words.size();
        for(int i=0;i<n-1;i++){
            // cout<<words[i]<<" "<<words[i+1]<<endl;
            int j;
            for(j=0;j<words[i].size();j++){
                char c1 = words[i][j];
                char c2;
                if(j<words[i+1].size()){
                    c2 = words[i+1][j];
                } else {
                    break;
                }
                if(c1!=c2){
                    indegree[c2]++;
                    if(!indegree.count(c1)){
                        indegree[c1] = 0;
                    }
                    // cout<<c1<<" "<<c2<<endl;
                    neighbs[c1].push_back(c2);
                    break;
                } else {
                    if(!indegree.count(c1)){
                        indegree[c1] = 0;
                    }
                }
            }
            for(int k=j;k<words[i].size();k++){
                char c1 = words[i][k];
                if(!indegree.count(c1)){
                    indegree[c1] = 0;
                }
            }
            for(int k=j;k<words[i+1].size();k++){
                char c1 = words[i+1][k];
                if(!indegree.count(c1)){
                    indegree[c1] = 0;
                }
            }
            
            
            
        }
    }
};