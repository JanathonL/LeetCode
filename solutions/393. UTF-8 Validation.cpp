393. UTF-8 Validation
class Solution {
public:
    int get8bits(int a){
        return a&0xFF;
    }
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int i = 0;
        int mask = 1<<7;
        if(data.size()==0) return true;
        while(i<len){
            mask = 1<<7;
            int num = get8bits(data[i]);
            int cnt = 0;
            while((num&mask)){
                cnt++;
                mask = mask>>1;
            }
            if(cnt>4 || cnt == 1) return false;
            if(cnt == 0){
                i++;
                continue;
            }
            
            while(--cnt){
                num = get8bits(data[++i]);
                if((num&(1<<7))&&((num&(1<<6))==0)){
                    continue;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};