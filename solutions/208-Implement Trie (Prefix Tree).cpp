// 208-Implement Trie (Prefix Tree)
// 前缀树构建
// 其实整个树构建起来比较简单（之前一直觉得这个东西应该很难。。）
// 主要就是两个属性，一个是
// bool key 判断当前这个是否是某个单词结尾
// trie* children[26] 26个字母的孩子，一开始都是nullptr

// insert函数就是一个字母一个字母进行插入，每次都是判断一下这个字母在树中存在了么，如果不存在就新建一个，
// 然后等到单词的字母都插进去了，就把当前这个node的key设置为true

// search和startswith基本一样，都是一个一个比较，如果遇到word中的字符，在trie中没有就return false。 
// 最后的时候，search的话还要判断一下当前这个字符是不是word的结尾，startswith的话，直接return true就好了。

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        key = false;
        children=vector<Trie*>(26,nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        while(word.size()>0){
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                node->children[k]=new Trie();
            }
            node=node->children[k];
            word=word.substr(1);
        }
        node->key=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        while(word.size()>0){
            int k= word[0]-'a';
            if(node->children[k]==nullptr){
                return false;
            }
            node = node->children[k];
            word = word.substr(1);
        }
        return node->key;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        while(prefix.size()>0){
            int k= prefix[0]-'a';
            if(node->children[k]==nullptr){
                return false;
            }
            node = node->children[k];
            prefix = prefix.substr(1);
        }
        return true;
    }
    void setKey(bool b){
        key = b;
    }
private:
    bool key;
    vector<Trie*> children;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */