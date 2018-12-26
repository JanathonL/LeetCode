class LRUCache{
    size_t capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> freq_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):capacity(capacity) {
    }
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        freq_list.splice(freq_list.begin(), freq_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            freq_list.splice(freq_list.begin(), freq_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == capacity) //reached capacity
        {
           int key_to_del = freq_list.back().first; 
           freq_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        freq_list.insert(freq_list.begin(), {key,value});  //create new node in list
        m_map[key] = freq_list.begin();       //create correspondence between key and node
    }
};