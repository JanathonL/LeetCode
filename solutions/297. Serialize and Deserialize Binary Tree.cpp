// 297. Serialize and Deserialize Binary Tree
// 随便选一种遍历方式都可以，只要把nullptr也表示出来，比如说表示成”#”,然后又用同样的方式生成回去。
// 这时候可以使用’,’进行分割，然后使用stringstream进行操作，十分方便，每次找节点val就可以使用getline(ss,str,’,’); 
// ss自动会向后遍历，只需要传入ss的引用就好了。
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
        if(!root) return "#";
        else return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        stringstream s(data);
        return cal(s);
    }
    TreeNode* cal(stringstream& s){
        string str;
        getline(s,str,',');
        if(str=="#"){
            return nullptr;
        }
        else{
            TreeNode* tree = new TreeNode(stoi(str));
            tree->left = cal(s);
            tree->right = cal(s);
            return tree;
        }
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));