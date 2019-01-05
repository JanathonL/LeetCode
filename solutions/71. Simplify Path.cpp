71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string tmp = "";
        for(int i =0;i<path.size();i++){
            if(path[i]!='/'){
                tmp+=path[i];
            }
            else{
                // cout<<"tmp:"<<tmp<<endl;
                if(tmp==".."&&!s.empty()){
                    s.pop();
                }
                else if(tmp==".."){
                    ;
                }
                else if(tmp!="."&&tmp!=""){
                    s.push(tmp);
                }
                else{
                    tmp="";
                }
                tmp="";
            }
        }
        if(tmp==".."&&!s.empty()){
            s.pop();
        }
        if(tmp!=""&&tmp!="."&&tmp!="..") {
            // cout<<tmp<<endl;
            s.push(tmp);
        }
        string ans = "";
        vector<string> test;
        while(!s.empty()){
            tmp=s.top();
            s.pop();
            // ans+="/"+tmp;
            test.push_back(tmp);
            
            
        }
        reverse(test.begin(),test.end());
        for(int i =0;i<test.size();i++){
            ans+="/"+test[i];
        }
        if(ans.size()==0) ans = "/";
        return ans;
    }
};

// refined
// using deque
// beats 78%
// time: O(N)
// space: O(N)
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        string tmp = "";
        for(int i =0;i<path.size();i++){
            if(path[i]!='/'){
                tmp+=path[i];
            }
            else{
                if(tmp==".."&&!s.empty()){
                    s.pop_back();
                } else if(tmp!="."&&tmp!=""&&tmp!="..") {
                    s.push_back(tmp);
                }
                tmp="";
            }
        }
        if(tmp==".."&&!s.empty()){
            s.pop_back();
        } else if(tmp!=""&&tmp!="."&&tmp!="..") {
            s.push_back(tmp);
        }
        string ans = "";
        vector<string> test;
        while(!s.empty()){
            tmp=s.front();
            s.pop_front();
            ans+="/"+tmp;
        }
        if(ans.size()==0) ans = "/";
        return ans;
    }
};