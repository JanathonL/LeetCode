449. Serialize and Deserialize BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        preorder(root, res);
        // cout<<res<<endl;
        return res;
    }
    void preorder(TreeNode* root, string& res){
        if(root==NULL){
            return;
        }
        if(res==""){
            res += to_string(root->val);
        }
        else{
            res+= " "+ to_string(root->val);
        }
        preorder(root->left, res);
        preorder(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> arr;
        // cout<<data<<endl;
        for(int i=0;i<data.size();i++){
            int pos = data.find(" ",i);
            // cout<<"pos:"<<pos<<endl;
            if(pos!=string::npos){
                // cout<<data.substr(i,pos-i)<<endl;
                arr.push_back(stoi(data.substr(i,pos-i)));
            }
            else{
                
                // cout<<data.substr(i)<<endl;
                arr.push_back(stoi(data.substr(i)));
                break;
                
            }
            i = pos;
        }
        int start = 0;
        // cout<<"test"<<endl;
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        return build(arr, start, INT_MIN, INT_MAX);
    }
    TreeNode* build(vector<int> arr, int& start, int low, int high){
        // cout<<"low:"<<low<<" high:"<<high<<" start:"<<start<<endl;
        if(start>=arr.size()) return NULL;
        TreeNode* root = NULL;
        if(arr[start]>low && arr[start]<high){
            // cout<<start<<" arr:"<<arr[start]<<endl;
            root = new TreeNode(arr[start]);
            int key = arr[start];
            start++;
            
            root->left = build(arr, start, low,key);
            root->right = build(arr, start, key, high);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));