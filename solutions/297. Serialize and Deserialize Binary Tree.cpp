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
    /*
        9 min
        1 wrong
        time: O(N)
        space: O(N)
    */
    void serialize_helper(TreeNode* root, string& res){
        if(root == NULL){
            res += "null,";
            return;     // 注意这个NULL需要return
        }
        res += to_string(root->val) + ",";
        serialize_helper(root->left, res);
        serialize_helper(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize_helper(root, res);
        return res;
    }
    TreeNode* deserialize_helper(istringstream& is){
        string word;
        TreeNode* root = NULL;
        if(getline(is, word, ',')) {
            if(word!="null"){
                root = new TreeNode(stoi(word));   // 注意这里需要stoi(word)
                root->left = deserialize_helper(is);
                root->right = deserialize_helper(is);
            } else {
                return NULL;
            }
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize_helper(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));