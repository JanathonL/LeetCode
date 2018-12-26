331. Verify Preorder Serialization of a Binary Tree
class Solution {
public:
    bool isValidSerialization(string preorder) {
         return valid(preorder)&&preorder.size()==0;
    }
    bool valid(string& preorder){
        // cout<<preorder.size()<<endl;
        if(preorder.size()==0){
            return false;
        }
        int ind= preorder.find_first_of(",");
        // cout<<ind<<endl;
        string str = preorder.substr(0,ind);
        if(ind==-1){
            preorder="";
        }
        else{
            preorder=preorder.substr(ind+1);
        }
        if(str=="#") {
            
            return true;
        }
        else {
            return valid(preorder)&valid(preorder);
        }
    }
    
};