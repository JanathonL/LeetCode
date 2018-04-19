// 211. Add and Search Word - Data structure design
// Trie树做，插入和正常的一模一样
// 查找的时候，自己再写一个递归的 find(Trie* node, word)
// 判断一下，if word.size() == 0 ->  return node->key;
// if word[0] == ‘.’  那么就26个子树顺序去搜索， 一旦发现true了就停止搜索
// flag = flag || find(node->children[i], word.substr(1));
// else:
// if word[0] 的子树不存在就直接返回false
// else  return find(node->children[k], word.substr(1));

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        key = false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* node = this;
        while(word.size()>0){
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                node->children[k]=new WordDictionary();
            }
            node = node->children[k];
            word=word.substr(1);
        }
        node->key = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(this,word);
    }
    bool find(WordDictionary* node, string word){
        if(word.size()==0) return node->key;
        bool flag = false;
        if(word[0]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=nullptr){
                    flag = flag || find(node->children[i],word.substr(1));
                }
            }
        }
        else {
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                return false;
            }
            flag = flag || find(node->children[k],word.substr(1));
        }
        return flag;
    }
private:
    WordDictionary* children[26];
    bool key;
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */