398. Random Pick Index
class Solution {
public:
    Solution(vector<int> nums) {
        for(int i =0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=vector<int>();
                m[nums[i]].push_back(i);
            }
            else{
                m[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        int len = m[target].size();
        // cout<<len<<endl;
        // put_list(m[target]);
        int index = rand() % (len);
        // cout<<"index:"<<index<<endl;
        return m[target][index];
    }
    void put_list(vector<int> list){
        for(auto it = list.begin(); it!=list.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
unordered_map< int, vector<int>> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */