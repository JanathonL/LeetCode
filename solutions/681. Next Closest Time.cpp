681. Next Closest Time
class Solution {
public:
    void dfs(vector<int> current, int cnt, vector<int> visit, vector<int> nums, vector<vector<int>>& pairs){
        
        if(cnt==4){
            pairs.push_back(current);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            current.push_back(nums[i]);
            dfs(current, cnt+1, visit,nums,pairs);
            current.pop_back();
            // if(!visit[i]){
            //     visit[i]=1;
            //     current.push_back(nums[i]);
            //     dfs(current, cnt+1, visit,nums,pairs);
            //     current.pop_back();
            //     visit[i]=0;
            // }
        }
    }
    string nextClosestTime(string time) {
        vector<int> nums;
        for(int i=0;i<time.size();i++){
            if(time[i]==':') continue;
            else nums.push_back(time[i]-'0');
        }
        vector<vector<int>> pairs;
        vector<int> visit(nums.size(),0);
        vector<int> current;
        dfs(current, 0, visit, nums, pairs);

        vector<string> res;
        unordered_map<string,int> m;
        for(int i = 0;i<pairs.size();i++){
            char str[256];
            int hour = pairs[i][0]*10+pairs[i][1];
            int minute = pairs[i][2]*10+pairs[i][3];
            if(hour<24 && minute<60){
                sprintf(str, "%02d:%02d", hour,minute);
                string s(str);
                // res.push_back(s);
                
                if(m[s]==0){
                    res.push_back(s);
                    m[s]++;
                }
            }


        }
        sort(res.begin(),res.end());
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<endl;
        // }
        auto it = find(res.begin(), res.end(), time);
        if(++it==res.end()){
            return res[0];
        }
        else{
            return *(it);
        }
    }
};