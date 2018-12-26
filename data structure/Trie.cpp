// Trie.cpp
class Trie {
    class TreeNode{
        public:
        vector<TreeNode*> children;
        bool word;
        TreeNode():word(false){
            for(int i=0;i<26;i++){
                children.push_back(NULL);
            }
        }
    };
    
private:
    TreeNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie(){
        root = new TreeNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            int key = word[i]-'a';
            if(cur->children[key]==NULL){
                cur->children[key] = new TreeNode;
            }
            cur =  cur->children[key];
        }
        cur->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            int key = word[i]-'a';
            if(cur->children[key] == NULL){
                return false;
            }
            cur = cur->children[key];
        }
        return cur->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            int key = word[i]-'a';
            if(cur->children[key] == NULL){
                return false;
            }
            cur = cur->children[key];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */