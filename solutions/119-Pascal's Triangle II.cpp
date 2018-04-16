// 119. Pascal's Triangle II
// 和上面那题一模一样
// 还有不用额外空间的做法，从后向前更新数组就可以了。
//     vector<int> A(rowIndex+1, 0);
//     A[0] = 1;
//     for(int i=1; i<rowIndex+1; i++)
//         for(int j=i; j>=1; j--)
//             A[j] += A[j-1];

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> first;
        int cnt = 0;
        while(cnt<=rowIndex){
            int n = first.size();
            vector<int> tmp;
            for(int i=0;i<n;i++){
                if(i==0){
                    tmp.push_back(first[i]);
                }
                else{
                    tmp.push_back(first[i]+first[i-1]);
                }
            }
            tmp.push_back(1);
            first=tmp;
            cnt++;
        }
        return first;
    }
};