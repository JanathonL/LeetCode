282. Expression Add Operators
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        cal(res,num,target,"",0,0,0);
        return res;
    }
    void cal(vector<string>& res, string num, int target, string path, int start, long eval, long mul){
        if(start==num.size()){
            if(eval==target){
                res.push_back(path);
                return;
            }
        }
        for(int i=start;i<num.size();i++){
            if(i!=start&&num[start]=='0') break;
            long cur=stol(num.substr(start,i-start+1));
            // cout<<cur<<endl;
            if(start==0){
                cal(res,num,target,path+to_string(cur),i+1,cur,cur);
            }
            else{
                cal(res,num,target,path+"+"+to_string(cur),i+1,eval+cur,cur);
                cal(res,num,target,path+"-"+to_string(cur),i+1,eval-cur,-cur);
                cal(res,num,target,path+"*"+to_string(cur),i+1,eval-mul+mul*cur,mul*cur);
            }
        }
    }
};