211. Add and Search Word - Data structure design
/*
30 min
7 wrongs

*/
class WordDictionary {
public:
    class TrieNode{
    public:
        bool is_word;
        vector<TrieNode*> children;
        TrieNode(){
            is_word = false;
            for(int i=0;i<26;i++){
                children.push_back(NULL);
            }
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {  //  O(N)
        TrieNode* cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(cur->children[index] == NULL){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {  // O(N + 26^k)  k is number of '.'
        TrieNode* cur = root;
        return dfs(word,0, cur);
    }
    bool dfs(string word, int pos, TrieNode* cur){
        if(pos==word.size()){
            // cout<<cur->is_word<<endl;
            return cur->is_word;
        }
        bool res = false;
        for(int i=pos;i<word.size();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(cur->children[j]){
                        res = dfs(word, i+1, cur->children[j]);
                    }
                    if(res){  //一定要现在就要判断，剪枝
                        return true;
                    }
                }
                return false;
            } else {
                int index = word[i]-'a';
                if(cur->children[index] == NULL){
                    return false;
                }
                cur = cur->children[index];
            }
        }
        return cur->is_word;
    }
TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */