// 241. Different Ways to Add Parentheses
// 分治的思想，我用每个操作符进行分割字符串，然后递归算出左右两边字符串可能的结果，最后把这些结果都两两组合使用之前分割的操作符进行操作。
// 递归结束的标志是当前字符串只有数字，可以使用 atoi(input.c_str()) 或者 stoi(input)，把这个数字push到res中，然后返回就可以了
// 还可以用一个unordered_map<string, vector<int>> 存一下之前算过的结果，节省时间
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