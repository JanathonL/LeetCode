// 68-Text Justification
// 这题的思路是先把每一行的最多摆放单词数找出来，
// 只要单词加起来的长度len+k-1<L, k是单词个数，L是每行长度。
// 然后去把空格算一下出来，要注意情况判断，应该有三种情况
// （1）	这行是最后一行，那么直接向左对齐，前面的空格都只有1，最后一个空格是补满长度L
// （2）	j-k-1>0，也就是说这行单词数多于1个，那么就是平均分配
// （3）	如果j-k-1==0，那么相当于左对齐，只要空格补满就好了
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        int i = 0;
        vector<string> res;
        while(i<words.size()){
            int j = i;
            int len = 0;
            while(j<words.size() && len+words[j].size()+j-i<=L){
                len += words[j++].size();
            }
            // cout<<len<<endl;
            int space = L-len;
            string tmp;
            int cnt = 0;
            if(space > 0){
                for(int k =i;k<j;k++){
                    cnt = 0;
                    tmp += words[k];
                    if(j==words.size()){
                        if(j-k-1==0) cnt = space;
                        else cnt = 1;
                    }
                    else if(j-k-1>0){
                        if(space%(j-k-1)==0) cnt = space / (j-k-1);
                        else cnt = space/(j-k-1)+1;
                    }
                    else{
                        cnt = space;
                    }
                    tmp.append(cnt,' ');
                    space -= cnt;
                }
                
            }
            else{
                tmp = words[i];
            }
            res.push_back(tmp);
            i=j;
        }
        return res;
    }
};