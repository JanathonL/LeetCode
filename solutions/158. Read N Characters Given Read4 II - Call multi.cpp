158. Read N Characters Given Read4 II - Call multiple times
// Forward declaration of the read4 API.
int read4(char *buf);
/*
total = 0
deal with buffer
    if buffer size > 0
        // read from buffer first
        total += size
while(n > 0){
    int num = read4(temp);
    if num > 0 {
        if(n>num){
            total += num;
            buf.append(temp);
            n -= num;
        } else {
            total += n;
            n = 0;
            buf.append(temp[0:n]);
            // push rest to queue
        }
    } else {
        break;
    }
}

30 min
5 wrongs
time: O(n)
space: O(1)
*/
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<char> buffer;
    int read(char *buf, int n) {
        int total = 0;
        string res;
        if(buffer.size()>0){
            if(n>=buffer.size()){
                total += buffer.size();
                n -= buffer.size();
                while(!buffer.empty()){
                    res.push_back(buffer.front());
                    buffer.pop();
                }
            } else {
                total += n;
                for(int i=0;i<n;i++){
                    res.push_back(buffer.front());
                    buffer.pop();
                }
                n = 0;
            }
        }
            
        while(n>0){
            char tmp[4];  // 记得要分配空间
            int num = read4(tmp);
            if(num>0){
                if(n>=num){
                    total += num;
                    n -= num;
                    for(int i=0;i<num;i++){
                        res += tmp[i];
                    }
                } else {
                    total += n;
                    for(int i=0;i<num-n;i++){
                        buffer.push(tmp[i+n]);
                    }
                    for(int i=0;i<n;i++){
                        res += tmp[i];   // 别忘了这里也要设置res
                    }
                    n = 0;
                }
            } else {
                break;
            }
        }
        char* cur = buf;   // 别忘了这里需要指针弄一下， buf不能变
        buf = (char*)malloc(sizeof(char)*(res.size()+1));  // 记得要注意malloc
        for(int i=0;i<res.size();i++){
            *cur = res[i];
            cur++;
        }
        cur = '\0';  // 别忘了末尾的'\0'
        return total;
    }
};