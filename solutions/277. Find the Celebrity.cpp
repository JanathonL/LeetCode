277. Find the Celebrity
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /*
    5 min
    1 wrong
    time: O(N)
    space: O(1)
    */
    int findCelebrity(int n) {
        if(n==0){
            return -1;
        }
        int candidate = 0;
        for(int i=1;i<n;i++){
            if(knows(candidate, i)){
                candidate = i;
            }
        }
        // check n-1 know candidate
        for(int i=0;i<n;i++){
            if(candidate==i) continue;   // 记得跳过自己
            if(!knows(candidate,i) && knows(i, candidate)){
                continue;
            } else {
                return -1;
            }
        }
        return candidate;
    }
};