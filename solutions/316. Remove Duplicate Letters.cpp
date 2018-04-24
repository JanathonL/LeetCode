// 316. Remove Duplicate Letters
// 贪心，从左到右我找最小的s[i]，如果s[i]左边的数都是可以减掉的，那就全部减掉，然后接着找下一个。
// 如果数是相等的，那就找靠近左边的那个 aba 就要保留第一个a，然后遇到不能删除的时候就停止，把当前最小的数保存一下，然后把后面这个数的全部删去。

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