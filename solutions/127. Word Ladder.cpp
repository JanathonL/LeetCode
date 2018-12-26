// 127. Word Ladder
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        minstep=INT_MAX;
        unordered_set<string> dict;
        queue<string> toVisit;
        toVisit.push(beginWord);
        for(int i = 0;i<wordList.size();i++){
            dict.insert(wordList[i]);
        }
        int dist = 1;
        while(!toVisit.empty()){
            
            int num = toVisit.size();
            
            for(int i =0;i<num;i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word==endWord) return dist;
                addNext(word,dict,toVisit);
            }
            dist++;
            
        }
        
        return 0;
    }
    void addNext(string beginWord, unordered_set<string>& dict, queue<string>& toVisit){

        for(int i =0; i<beginWord.size();i++){
            for(int j =0;j<26;j++){
                if(beginWord[i]==j+'a') continue;
                string old = beginWord;
                beginWord[i]=j+'a';
                if(dict.find(beginWord)!=dict.end()){
                    dict.erase(beginWord);
                    toVisit.push(beginWord);
                }
                    
                beginWord=old;
            }
        }
    }

private:
    int minstep;
    vector<int> visit;
};