299. Bulls and Cows
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, unordered_set<int>> m;
        unordered_set<int> visit;
        int cnta,cntb;
        cnta=cntb=0;
        for(int i=0;i<secret.size();i++){
            
            if(secret[i]==guess[i]){
                cnta++;
                visit.insert(i);
            }
            else{
                m[secret[i]].insert(i);
            }
        }
        for(int i=0;i<guess.size();i++){
            if(visit.find(i)!=visit.end()) continue;
            if(m.find(guess[i])!=m.end()){
                cntb++;
                char index = guess[i];
                m[index].erase(m[index].begin());
                if(m[index].size()==0){
                    m.erase(index);
                }
            }
        }
        return to_string(cnta)+"A"+to_string(cntb)+"B";
        
    }
};