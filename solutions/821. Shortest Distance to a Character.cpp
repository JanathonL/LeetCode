class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int next,last;
        vector<int> res;
        next=last=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(next==INT_MAX){
                next = s.find_first_of(c,i);
            }
            if(i<=next){
                // cout<<min(abs(next-i),abs(i-last))<<endl;
                res.push_back(min(abs(next-i),abs(i-last)));
            }
            else{
                last = next;
                next = s.find_first_of(c,i);
                if(next==-1) next=INT_MAX-1;
                // cout<<last<<endl;
                res.push_back(min(abs(next-i),abs(i-last)));
            }
            
        }
        return res;
    }
};