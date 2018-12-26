388. Longest Absolute File Path
class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> m;
        int res=0;
        int n = input.size();
        int level = 0;
        for(int i=0;i<n;i++){
            int start = i;
            // cout<<level<<endl;
            while(i<n && input[i]!='\n' && input[i]!='\t') i++;
            if(i>=n || input[i]=='\n'){
                string str = input.substr(start, i-start);
                // cout<<str<<endl;
                if(isdir(str)){
                    int prev = level > 0? m[level-1]:-1;
                    m[level] = prev + 1 + str.size();
                }
                else{
                    int prev = level > 0? m[level-1]:-1;
                    res = max(res, int(str.size()+prev+1));
                }
                level = 0;
            }
            else{
                level = 0;
                while(input[i+1]=='\t'){
                    i++;
                    level+=1;
                }
                level+=1;
            }
        }
        // put_list(m,"map");
        return res;
    }
    bool isdir(string str){
        return str.find(".")==string::npos;
    }
    void put_list(unordered_map<int,int> list, string name){
        cout<<name<<" ";
        for(auto it = list.begin();it!=list.end();it++){
            cout<<it->first<<" "<<it->second<<" "<<endl;
        }
        cout<<endl;
    }
};