406. Queue Reconstruction by Height
class Solution {
public:
    static bool cmp(pair<int, int> first, pair<int,int> second){
        if(first.second != second.second){
            return first.second<second.second;
        }
        else{
            return first.first<second.first;
        }
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        sort(people.begin(),people.end(), cmp);
        list<pair<int, int>> res_list;
        for(int i=0;i<len;i++){
            int ind = 0;
            if(res_list.empty()){
                res_list.push_back(people[i]);
            }
            else{
                int cnt = 0;
                bool inserted = false;
                for(auto it = res_list.begin(); it!=res_list.end();it++){
                    if(it->first >= people[i].first){
                        cnt++;
                    }
                    if(cnt>people[i].second){
                        res_list.insert(it,people[i]);
                        inserted = true;
                        break;
                    }
                }
                if(!inserted){
                    res_list.push_back(people[i]);
                }
            }
        }
        vector<pair<int,int>> res;
        for(auto it = res_list.begin(); it!=res_list.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};