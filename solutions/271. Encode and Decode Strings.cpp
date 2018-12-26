271. Encode and Decode Strings
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        res+=to_string(strs.size())+"#";
        for(int i=0;i<strs.size();i++){
            res+=to_string(strs[i].size())+"#"+strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string str) {
        int pos = str.find('#',0);
        int n = stoi(str.substr(0,pos));
        vector<string> res;
        for(int i=0;i<n;i++){
            int new_pos = str.find('#',pos+1);
            int len = stoi(str.substr(pos+1,new_pos-pos-1));
            res.push_back(str.substr(new_pos+1,len));
            pos = new_pos+len;
        }
        return res;
    }
    
    
  
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));