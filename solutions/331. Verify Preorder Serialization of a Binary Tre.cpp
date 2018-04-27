// 331. Verify Preorder Serialization of a Binary Tree
// Time: O(n)
// 相当于模拟一遍建树，只不过不用建起来，递归写一写就好了，注意要判断一下，最后建完树之后的字符串是否为空，是的话，就可以了，否则就是错的。

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