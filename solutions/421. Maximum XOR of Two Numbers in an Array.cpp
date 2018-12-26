421. Maximum XOR of Two Numbers in an Array
class Trie{
    public:
    int num;
    Trie* children[2];
};
class Solution {
public:
    Trie* newnode(){
        Trie *temp = new Trie;
        temp->children[0]=temp->children[1]=NULL;
        temp->num = 0;
        return temp;
    }
    void insert(Trie* root, unsigned int n){
        root->num = n;
        for(int i=31;i>=0;i--){
            bool res = ((n)&(1<<i));
            if(root->children[res]==NULL)root->children[res]=newnode();
            root=root->children[res];
        }
        root->num = n;
    }
    int fxor(Trie* root, unsigned int n){
        // cout<<"begin search n:"<<n<<endl;
        for(int i=31;i>=0;i--){
            bool res = ((n)&(1<<i));
                            // cout<<(int)res;

            if(root->children[!res]!=NULL)
            {
                root=root->children[!res];
            }
            else if(root->children[res]!=NULL){
                // cout<<(int)!res;
                root=root->children[res];
            }
        }
        // cout<<endl;
        // cout<<"find num:"<<root->num<<endl;
        return (root->num)^(n);
    }
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = newnode();
        if(nums.size()<2){
            return 0;
        }
        insert(root, nums[0]);
        int mmax = INT_MIN;
        for(int i=1;i<nums.size();i++){
            mmax = max(mmax, fxor(root,nums[i]));
            insert(root, nums[i]);
        }
        return mmax;
    }
};