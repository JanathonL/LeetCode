904. Fruit Into Baskets
// refined beat 30%
// time: O(N)
// space: O(1)
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> dict;
        int j = 0;
        int max_len = 0;
        for(int i=0;i<tree.size();i++){
            dict[tree[i]]++;
            if(dict.size()>2){
                dict[tree[j]]--;
                if(dict[tree[j]]==0){
                    dict.erase(tree[j]);
                }
                j++;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};