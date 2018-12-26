381. Insert Delete GetRandom O(1) - Duplicates allowed
class RandomizedCollection {
public:
    
    
    
    
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)==m.end()){
            unordered_set<int> tmp;
            tmp.insert(nums.size());
            m[val]=tmp;
            nums.push_back(val);
            return true;
        }
        else{
            m[val].insert(nums.size());
            nums.push_back(val);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end()){
            return false;
        }
        else{
            
            int last = nums.back();
            if(last == val){
                m[last].erase(nums.size()-1);
                nums.pop_back();
                if(m[val].empty()){
                    m.erase(val);
            }
                return true;
            }
            
            
            int ind = *(m[val].begin());
            
            // put_list(m[val],"val");
            // put_list(m[last],"last");
            // print_nums(nums,"nums:");
            
            m[last].erase(nums.size()-1);
            m[last].insert(ind);
            
            nums[ind]=last;
            nums.pop_back();
            
            m[val].erase(ind);
            
//             string s=  std::to_string(val);
//             string str = string("after val ");
//             str += s;
            
//             print_nums(nums,"after nums:");
//             put_list(m[val],str);
//             put_list(m[last],"after last");
            if(m[val].empty()){
                m.erase(val);
            }
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    unordered_map<int, unordered_set<int>> m;
    vector<int> nums;
    void put_list(auto list, string name){
        cout<<name<<" :";
        for(auto it = list.begin();it!=list.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    void print_nums(vector<int> nums, string name){
        cout<<name<<" ";
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */