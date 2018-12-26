// 460. LFU Cache
// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LFUCache cache = new LFUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
class LFUCache {
public:
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>::iterator> miter;
    unordered_map<int, list<int>> mf;
    int minfreq;
    int capacity;
    LFUCache(int capacity):capacity(capacity) {
        minfreq = 0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        mf[m[key].second].erase(miter[key]);
        m[key].second++;
        mf[m[key].second].push_back(key);
        miter[key] = --mf[m[key].second].end();
        if(mf[minfreq].size()==0){
            minfreq++;
        }
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(capacity<=0) return;
        if(m.find(key)!=m.end()){
            int val = get(key);
            m[key].first = value;
            return;
        }
        else{
            if(m.size()>=capacity){
                int rmkey = mf[minfreq].front();
                m.erase(rmkey);
                miter.erase(rmkey);
                mf[minfreq].pop_front();
            }
            m[key] = {value,1};
            mf[1].push_back(key);
            miter[key] = --mf[1].end();
            
        }
        minfreq=1;
        return ;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */