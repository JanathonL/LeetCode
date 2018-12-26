// 243. Shortest Word Distance
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1=-1;
        int pos2=-1;
        int res=INT_MAX;
        for(int i=0;i<words.size();i++){
            if(word1==words[i]){
                pos1=i;
                if(pos2!=-1){
                    res = min(res, pos1-pos2);    
                }
            }
            else if(word2==words[i]){
                pos2=i;
                if(pos1!=-1){
                    res = min(res, pos2-pos1);
                }
            }
        }
        return res;
    }
};