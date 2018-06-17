// 380. Insert Delete GetRandom O(1)
// 我使用了两个hash_map一个stack
// m1[data] = index
// m2[index]=data
// stack里面存的是当前被删除的节点index

// insert：判断一下m1是否找得到val，如果不存在那就去看看stack是否为空，不为空就pop一个插入即可，如果为空就cnt++，然后index=cnt
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m1,m2;
    int cnt =0;
    stack<int> s;
    RandomizedSet() {
        
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(this->m1.find(val)!=this->m1.end()){
            return false;
        }
        else{
            int ind = 0;
            if(s.empty()){
                ind = cnt;
                cnt++;
            }
            else{
                ind = s.top();
                s.pop();
            }
            m1[val]=ind;
            m2[ind]=val;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(this->m1.find(val)==this->m1.end()){
            return false;
        }
        else{
            int ind = this->m1[val];
            this->m1.erase(val);
            this->m2.erase(ind);
            this->s.push(ind);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        while(1){
            int ind = 0 + (rand() % static_cast<int>(this->cnt - 0 + 1));
            if(this->m2.find(ind)!=this->m2.end()){
                return this->m2[ind];
            }
        }
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */