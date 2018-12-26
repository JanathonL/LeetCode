403. Frog Jump
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        // vector<vector<bool>> dp(len, (len,0));
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int start = stones[i];
                int end = stones[j];
                if(start*2-end+1 < 0){
                    break;
                }
                if(start*2-end>=0 && start*2-end <=start && dp[start].find(start*2 -end)!=dp[start].end()){
                    dp[end].insert(start);
                }
                else if(start*2-end-1>=0 && start*2-end-1<=start && dp[start].find(start*2-end-1)!=dp[start].end()){
                    dp[end].insert(start);
                }
                else if(start*2-end+1>=0 && start*2-end+1<=start && dp[start].find(start*2-end+1)!=dp[start].end()){
                    dp[end].insert(start);
                }
            }
        }
        
        return !dp[stones[len-1]].empty();
    }
};