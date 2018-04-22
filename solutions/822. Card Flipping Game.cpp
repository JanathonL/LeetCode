class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<pair<int,int>> data;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]<backs[i]) swap(fronts[i],backs[i]);
            data.push_back(make_pair(fronts[i],backs[i]));
            
        }
        sort(data.begin(),data.end(),cmp);
        int small=INT_MAX;
        for(int i=0;i<data.size();i++){
            int tmp1 = data[i].second;
            int tmp2 = data[i].first;
            
            bool isok1=true;
            bool isok2=true;
            for(int j=0;j<data.size();j++){
                if(data[j].first==tmp1&&data[j].second==tmp1){
                    // cout<<"tmp1 i:"<<i<<" j:"<<j<<endl;
                    isok1=false;
                }
                if(data[j].first==tmp2&&data[j].second==tmp2){
                    // cout<<"tmp2 i:"<<i<<" j:"<<j<<endl;
                    isok2=false;
                }
            }
            // if(tmp2==5) cout<<isok2<<endl;
            if(isok1){
                small=min(small,tmp1);
            }
            else if(isok2){
                small=min(small,tmp2);
            }
            
            
        }
        if(small==INT_MAX){
            return 0;
        }
        return small;
    }
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second<b.second){
            return 1;
        }
        else if(a.second>b.second){
            return 0;
        }
        else{
            return a.first<b.first;
        }
    }
};