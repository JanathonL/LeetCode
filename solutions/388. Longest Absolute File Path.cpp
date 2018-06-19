// 388. Longest Absolute File Path
// 这题可以使用一个map来存目录的深度和每个深度的长度，这里有一点要注意的是，一旦出现了新的同级目录（\t的数目一样），那么旧的目录就会被覆盖，所以直接更新新的目录长度就可以了。
// 注意判断一下如果是dir就更新目录长度，如果是文件就和之前的结果取最大的保留。
// 注意一点的是，每次计算完\n的情况之后，level都要归零，不然会影响到后面的计算。
// 比如这种情况 a\n\ttest.txt\na2   

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
