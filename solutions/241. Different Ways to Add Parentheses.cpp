241. Different Ways to Add Parentheses
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(m.find(input)!=m.end()) return m[input];
        vector<int> res;
        for(int i=0;i<input.size();i++){
            if(input[i]=='-'||input[i]=='*'||input[i]=='+'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(auto l:left){
                    for(auto r:right){
                        if(input[i]=='-'){
                            res.push_back(l-r);
                        }
                        else if(input[i]=='+'){
                            res.push_back(l+r);
                        }
                        else{
                            res.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(atoi(input.c_str()));
        }
        m[input]=res;
        return res;
    }
private:
    unordered_map<string,vector<int>> m;
};