// 187. Repeated DNA Sequences
// 简单的方法是直接用一个hashmap把所有的子串进行计数，然后大于1次的输出
// 还可以用hash值进行字符串编码
// hash = hash<<2 | hashvalue(str[i]);

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> myset;
        if(s.size()<10) return vector<string>();
        vector<string> result;
        for(int i =0;i<s.size()-9;i++){
            string tmp = s.substr(i,10);
            int hv = hashcode(tmp);
            if(myset.find(hv)==myset.end()){
                myset.insert(hv);
            }
            else if(find(result.begin(),result.end(),tmp)==result.end()){
                result.push_back(tmp);
            }
        }
        
        return result;
    }
    int hashcode(string s){
        int hash = 0;
        for(int i =0;i<s.size();i++){
            hash = (hash<<2) | hv(s[i]);
        }
        return hash;
    }
    int hv(char c){
        switch(c){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
    
};
// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<string,int> m;
//         if(s.size()<10) return vector<string>();
//         for(int i =0;i<s.size()-9;i++){
//             string tmp = s.substr(i,10);
//             if(m.find(tmp)==m.end()){
//                 m[tmp]=1;
//             }
//             else{
//                 m[tmp]+=1;
//             }
//         }
//         vector<string> result;
//         for(auto it:m){
//             if(it.second>1){
//                 result.push_back(it.first);
//             }
//         }
//         return result;
//     }
    
// };