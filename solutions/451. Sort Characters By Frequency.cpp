451. Sort Characters By Frequency
class Solution {
public:
    /*
    9 min
    time: O(N)
    space: O(N) total 2n
    */
    string frequencySort(string s) {
        // check empty
        if(s.size()==0){
            return "";
        }
        string res;
        // use a hash table get frequency
        unordered_map<char, int> dict;
        for(char c:s){
            dict[c]++;
        }
        // use a vector<vector<int>> to sort
        vector<vector<int>> freq(s.size()+1);
        for(auto item: dict){
            int cnt = item.second;
            freq[cnt].push_back(item.first);
        }
        for(int i=freq.size()-1;i>=0;i--){  // // O(N)
            for(int j=0;j<freq[i].size();j++){ 
                res += string(i, freq[i][j]);
            }
        }
        return res;
    }
};