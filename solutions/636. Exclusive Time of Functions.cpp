636. Exclusive Time of Functions
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> m(n,0);
        stack<int> s;
        int oldlogid = -1;
        int oldtime = -1;
        string oldcondition = "";
        for(int i=0;i<logs.size();i++){
            int pos = logs[i].find(":");
            // cout<<stoi(logs[i].substr(0, pos))<<endl;
            int logid = stoi(logs[i].substr(0, pos));
            int pos1 = logs[i].find(":", pos+1);
            string condition = logs[i].substr(pos+1,pos1-pos-1);
            // cout<<condition<<endl;
            // cout<<logs[i].substr(pos1+1)<<endl;
            int time = stoi(logs[i].substr(pos1+1));
            if(condition == "start"){
                if(oldlogid==-1){
                    ;
                }
                else{
                    if(oldcondition=="end"){
                        m[s.top()]+= time-oldtime-1;
                    }
                    else{
                        m[s.top()]+= time-oldtime;
                    }
                    
                }
                s.push(logid);
            }
            else{
                if(oldcondition == "start" ){
                    m[s.top()] += time-oldtime+1;
                    
                }
                else{
                    // cout<<logid<< " "<<time-oldtime;
                    m[logid] += time-oldtime;
                }
                s.pop();
            }
            oldlogid = logid;
            oldcondition = condition;
            oldtime = time;
        }
        return m;
    }
};