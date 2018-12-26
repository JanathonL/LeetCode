// 244. Shortest Word Distance II
// Design a class which receives a list of words in the constructor, and implements a method that takes 
// two words word1 and word2 and return the shortest distance between these two words in the list. 
// Your method will be called repeatedly many times with different parameters. 

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
class WordDistance {
public:
    WordDistance(vector<string> words): words(words) {
        for(int i=0;i<words.size();i++){
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for(int i =0;i<m[word1].size();i++){
            for(int j=0;j<m[word2].size();j++){
                res = min(res, abs(m[word2][j]-m[word1][i]));
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> m;
    vector<string> words;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */