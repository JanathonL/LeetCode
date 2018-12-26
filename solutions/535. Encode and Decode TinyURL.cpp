535. Encode and Decode TinyURL
class Solution {
public:
    unordered_map<string,string> m;
    int cnt=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        cnt++;
        string res = "http://test.com/"+to_string(cnt);
        m[res]=longUrl;
        return res;
    }
    size_t hash(string str){
        std::hash<std::string> hash_fn;
        size_t res = hash_fn(str);
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));