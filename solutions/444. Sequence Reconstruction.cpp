444. Sequence Reconstruction

/* reconstruction -> shortest sequence
    if only one and it is org sequence
        return true
    else 
        return false
    
    
    target = reconstruction
    check target == org
    
    reconstruction:
        gen supersequences
        check only one
        if only one:
            return target
        else:
            return [] -> invalid
    
    gen supersequence
        topo sort
            indegree ([1,2] -> indeg[1]=0, indeg[2]=1)
            use a queue
            1. push all elements with indegree 0   -> if there is more than 1 element -> return []
            while(!queue.empty()){
                push_back cur to the res 
                check cur nei
                push cur nei
                if more than 1 element is pushed to the queue return []
            }
            if res.size() == indeg.size()
                return res
            else
                return []

refined: beat 50%
time: O(V*E)
space: O(V)

*/

class Solution {
public:
    bool reconstruction(vector<vector<int>> seqs, vector<int>& target, int n){
        vector<int> indeg(n,-1);
        unordered_map<int, unordered_set<int>> neighbors;
        for(vector<int> seq:seqs){
            if(seq.size()>0){
                if(seq[0]-1>=n || seq[0]-1<0) return false;
                if(indeg[seq[0]-1]==-1){
                    indeg[seq[0]-1] = 0;
                }
            }
            for(int i=1;i<seq.size();i++){
                if(seq[i]-1>=n || seq[i]-1<0) return false;
                if(neighbors.count(seq[i-1]-1)&&neighbors[seq[i-1]-1].count(seq[i]-1)) continue;
                if(indeg[seq[i]-1]==-1){
                    indeg[seq[i]-1] = 0;
                }
                indeg[seq[i]-1]++;
                neighbors[seq[i-1]-1].insert(seq[i]-1);
            }
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()){
            if(que.size()>1){
                return false;
            }
            int cur = que.front();
            que.pop();
            res.push_back(cur+1);
            for(int nei:neighbors[cur]){
                indeg[nei]--;
                if(indeg[nei]==0){
                    que.push(nei);
                }
            }
        }
        if(res.size()==n){
            target = res;
            return true;
        } else {
            return false;
        }
    }
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<int> target;
        bool res = reconstruction(seqs, target, org.size());
        if(!res) return res;
        return target==org;
    }
};