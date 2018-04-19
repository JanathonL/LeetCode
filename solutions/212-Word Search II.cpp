// 212. Word Search II
// 思路是用 Trie树加上dfs回溯
// 坑点：
// （1） 需要用一个hash_set去重
// （2） 不能因为hash_set中有了这个元素就return，可能后续还有其他子串是由这个word开始的。

class Trie{
public:
    Trie(){
        key=false;
        children=vector<Trie*>(26,nullptr);
    }
    void insert(string word){
        Trie* node = this;
        while(word.size()>0){
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                node->children[k]=new Trie();
            }
            node = node->children[k];
            word = word.substr(1);
        }
        node->key = true;
    }
    bool search(string word){
        Trie* node = this;
        while(word.size()>0){
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                return false;
            }
            node = node->children[k];
            word = word.substr(1);
        }
        return node->key;
    }
    bool startWith(string word){
        Trie* node = this;
        while(word.size()>0){
            int k = word[0]-'a';
            if(node->children[k]==nullptr){
                return false;
            }
            node = node->children[k];
            word = word.substr(1);
        }
        return true;
    }
private:
    bool key;
    vector<Trie*> children;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        int n = board.size();
        if(n==0) return vector<string> ();
        int m = board[0].size();
        for(int i=0;i<words.size();i++){
            root->insert(words[i]);
        }
        string path;
        vector<vector<int>> visit(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,root,i,j,path,visit);
            }
        }
        for(auto it:s){
            res.push_back(it);
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, Trie* root, int x, int y, string path, vector<vector<int>> visit){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()) return ;
        if(visit[x][y]) return;
        path += board[x][y];
        if(!(root->startWith(path))) return;

        if(root->search(path)){
            s.insert(path);
        }
        visit[x][y]=1;
        
        dfs(board,root,x+1,y,path,visit);
        dfs(board,root,x-1,y,path,visit);
        dfs(board,root,x,y+1,path,visit);
        dfs(board,root,x,y-1,path,visit);
        
        
        visit[x][y]=0;
        
        
    }
private:
    vector<string> res;
    unordered_set<string> s;
};