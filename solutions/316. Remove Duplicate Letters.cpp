316. Remove Duplicate Letters
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size()==0) return "";
        vector<int> array(26,0);
        string after;
        for(int i=0;i<s.size();i++){
            array[s[i]-'a']++;
        }
        int pos=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]<s[pos]) pos=i;
            if(--array[s[i]-'a']==0) break;
        }
        
        if(s.size()==0) return "";
        char c = s[pos];
        s=s.substr(pos+1);
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
        string ans;
        ans += c;
        ans +=removeDuplicateLetters(s);
        return ans;
    }
    
};
// DFS TLE
// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         if(s.size()==0) return "";
//         vector<int> array(26,0);
//         string after;
//         for(int i=0;i<s.size()-1;i++){
//             if(s[i]==s[i+1]) continue;
//             after+=s[i];
//             array[s[i]-'a']++;
//         }
//         if(after[after.size()-1]!=s[s.size()-1]){
//             after+=s[s.size()-1];
//             array[s[s.size()-1]-'a']++;
//         }
//         // cout<<after<<endl;
        
//         string best;
//         dfs(after,0,array,"",best);
//         return best;
//     }
//     void dfs(string s, int index, vector<int> array, string path, string& best){
//         if(index==s.size()){
//             for(int i=0;i<array.size();i++){
//                 if(array[i]>1) return;
//             }
//             if(best=="") best=path;
//             else{
//                 best = best.compare(path)>0? path:best;
//             }
//             return ;
//         }
//         bool flag=false;
//         if(array[s[index]-'a']>1){
//             array[s[index]-'a']--;
//             flag = true;
//             dfs(s,index+1,array,path,best);
//         }
//         if(flag){
//             array[s[index]-'a']++;
//         }
//         dfs(s,index+1,array,path+s[index],best);
        
        
//     }
// };