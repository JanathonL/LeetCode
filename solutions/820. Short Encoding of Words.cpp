820. Short Encoding of Words
class Solution {
public:
    static bool cmp(string a, string b){
        if(a.size()<b.size()){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        if(words.size()==0) return 0;
        for(int i=0;i<words.size();i++){
            father[words[i]]=words[i];
        }
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[j],words[i])){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    connect(words[i],words[j]);
                    break;
                }
            }
            
        }
        int cnt=0;
        unordered_set<string> s;
        for(auto item:father){
            if(s.find(item.second)!=s.end()) continue;
            cnt++;
            cnt+=item.second.size();
            s.insert(item.second);
            // cout<<item.second<<endl;
        }
        return cnt;
    }
    bool check(string f, string c){
        if(f.size()<c.size()) return false;
        int i=f.size()-1;
        int j=c.size()-1;
        bool isok=true;
        while(i>=0&&j>=0){
            if(f[i]==c[j]) {
                i--;
                j--;
            }
            else{
                isok=false;
                break;
            }
        }
        return isok;
    }
    string find(string x){
        if(x==father[x]){
            return x;
        }
        else return find(father[x]);
    }
    void connect(string x, string y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        
        if(x.size()>y.size()){
            if(check(x,y))
                father[y]=x;
        }
        else{
            if(check(y,x))
                father[x]=y;
        }
    }
private:
    unordered_map<string,string> father;
};