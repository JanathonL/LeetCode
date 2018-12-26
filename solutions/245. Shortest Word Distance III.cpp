// 245. Shortest Word Distance III
// Medium
// 84
// 45


// Given a list of words and two words word1 and word2, return the shortest distance 
// between these two words in the list.

// word1 and word2 may be the same and they represent two individual words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “makes”, word2 = “coding”
// Output: 1
// Input: word1 = "makes", word2 = "makes"
// Output: 3
// Note:
// You may assume word1 and word2 are both in the list.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int last_for_word_1 = -1;
        int last_for_word_2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i)
        {
        	if (words[i]==word1)
        	{
        		if (last_for_word_2!=-1)
    			{
    				res = min(res, i-last_for_word_2);
    			}	
    			if (word1==word2 && last_for_word_1!=-1)
    			{
    				res = min(res, i-last_for_word_1);
    			}
        			last_for_word_1 = i;
        	} else if (words[i]==word2){
        		if (last_for_word_1!=-1)
        		{
        			res = min(res, i-last_for_word_1);
        		}
        		last_for_word_2 = i;
        	}
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{	
	string w[] = {"practice", "makes", "perfect", "coding", "makes"};
	vector<string> words(w, w+5);
	Solution slt;
	cout<<slt.shortestWordDistance(words, "makes", "makes")<<endl;
	return 0;
}

