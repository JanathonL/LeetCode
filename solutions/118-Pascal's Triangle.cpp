// 118. Pascal's Triangle
// Time: O(nums*(nums+1)/2)这题比较简单，注意一下边界的时候要加上0一起运算就好了，
// 然后如果是用num[i]+num[i-1] 这样做的话，别忘了最后末尾加一个1.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> first;
        vector<vector<int>> res;
        int cnt = 0;
        while(cnt<numRows){
            cnt++;
            vector<int> tmp;
            int n = first.size();
            for(int i=0;i<n;i++){
                if(i==0){
                    tmp.push_back(first[i]+0);
                }
                else{
                    tmp.push_back(first[i]+first[i-1]);
                }
            }
            tmp.push_back(1);
            res.push_back(tmp);
            first=tmp;
        }
        return res;
    }
};