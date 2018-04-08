// 813. Largest Sum of Averages
// DP Time: O(n^3),  Space: O(n^2)
// f[i][j]表示到第i个数为止进行j次分割的最大值
// f[i][j] = max(f[i][j], f[p][j-1] + (s[i]-s[p])/(i-p))

// attention:
// (1)	s[i]表示 a[0…i] 的累加和
// (2)	f[i][1] = s[i]/i;
// (3)	return f[n][K];
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        maxsum = 0;
        int n = A.size();
        if(n==0) return 0;
        vector<vector<double>> f(n+1,vector<double>(K+1,0));
        vector<double> s(n+1,0);
        for(int i =0;i<n;i++) s[i+1]=s[i]+A[i];
        
        for(int i=1;i<=n;i++) f[i][1] = s[i]/i;
        
        for(int i =1;i<=n;i++){
            for(int j=2;j<=K && j<=i;j++){
                for(int p=0;p<i;p++){
                    f[i][j]=max(f[i][j],f[p][j-1]+(s[i]-s[p])/(i-p));
                }
            }
        }
        return f[n][K];
    }
    
private:
    double maxsum;
};
// class Solution {
// public:
//     double largestSumOfAverages(vector<int>& A, int K) {
//         maxsum = 0;
//         if(A.size()==0) return 0;
//         vector<vector<int>> path;
//         dfs(A,0,path,K);
//         return maxsum;
//     }
//     void dfs(vector<int>& A, int start, vector<vector<int>> path, int k){
//         if(start==A.size()&&path.size()==k){
//             double sum = 0;
//             for(int i =0;i<k;i++){
//                 double avg = cal(path[i]);
//                 sum += avg;
//             }
//             maxsum = max(maxsum,sum);
//             return ;
//         }
//         else if(path.size()+A.size()-start<k){
//             return ;
//         }
//         for(int i =start; i<A.size();i++){
//             vector<int> tmp(A.begin()+start,A.begin()+i+1);
//             path.push_back(tmp);
//             dfs(A,i+1,path,k);
//             path.pop_back();
//         }
//     }
//     double cal(vector<int> path){
//         int n = path.size();
//         double sum = 0;
//         for(int i =0;i<n;i++){
//             sum += path[i]*1.0/n;
//         }
//         return sum;
//     }
// private:
//     double maxsum;
// };