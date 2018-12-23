464. Can I Win
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
         if(desiredTotal==0){
             return true;
         }
        if(desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2) return false;
        int visited = 0;
        unordered_map<int,bool> mem;
        return dfs(maxChoosableInteger, desiredTotal, visited, mem);
    }
    bool dfs(int range, int target, int visited, unordered_map<int,bool>& mem){
        if(target<=0){
            return false;
        }
        if(mem.count(visited)){
            return mem[visited];
        }
        for(int i=1;i<=range;i++){
            int mask = 1<<i;
            if(visited&mask) continue;
            if(!dfs(range, target-i, visited | mask, mem)){
                mem[visited] = true;
                return true;
            }
        }
        mem[visited] = false;
        return false;
    }
};