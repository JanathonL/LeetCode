// 299. Bulls and Cows
// 用两个vector记录secret和guess中每个数字出现的个数
// 第一次遍历的时候，如果发现secret和guess相等，那就cnta++，否则就把两个secret,guess的数组相应数字加1，
// 最后算b的时候，只要遍历一下secret和guess vector数组，把当前位置数字出现次数较小的那个加上就好了。
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