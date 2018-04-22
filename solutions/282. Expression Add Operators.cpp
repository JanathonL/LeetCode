// 282. Expression Add Operators
// 这题和之前的一到basic calculator很像，都是划分字符串，然后分治的思想。
// 这题主要的小trick有
// （1）	使用long来保存结果避免overflow
// （2）	用if(i!=start&&num[start]=='0') break; 来消除前导零的数字
// （3）	用一个mul的数来计算*的情况， eval = eval-mul+mul*cur,  mul = mul*cur这个的意思是先把之前加上或者减去的值先抵消掉，
//         然后加上现在*结果之后的值，然后把*的结果值更新成现在的值。
// （4）	计算+-的时候，那就是eval=eval+cur, mul= cur ;  eval=eval-cur, mul= -cur 
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