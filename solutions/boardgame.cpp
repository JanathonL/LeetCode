#include <vector>
using namespace std;
int min_cnt = INT_MAX;
int dfs(vector<vector<char>>& m,vector<vector<int>>& dp, int x, int y, int cur){
	if(dp[x][y]>=0){
		return dp[x][y];
	}
	if(x==m.size()) {
		res[y]=min(res[y],cur);
		return cur;
	}
	vector<vector<int>> dirs = {{0,1},{1,0},{0,-1}};
	int res = INT_MAX;
	for(auto dir:dirs){
		int nx = x+dir[0];
		int ny = y+dir[0];

		if(nx>=0&&nx<=m.size()&&ny>=0&&ny<m[0].size()&&dp[nx][ny]==-1){
			if(m[x][y]=='*'){
				res = min(res, dfs(m,dp,nx,ny,cur+1));
			}
			else if(m[x][y]=='R'){
				if(dir=={0,1}){
					res = min(res, dfs(m,dp,nx,ny,cur));
				}
				else{
					res = min(res, dfs(m,dp,nx,ny,cur+1));
				}
			}
			else if(m[x][y]=='L'){
				if(dir=={0,-1}){
					res = min(res, dfs(m,dp,nx,ny,cur));
				}
				else{
					res = min(res, dfs(m,dp,nx,ny,cur+1));
				}
			}
			else if(m[x][y]=='D'){
				if(dir=={1,0}){
					res = min(res, dfs(m,dp,nx,ny,cur));
				}
				else{
					res = min(res, dfs(m,dp,nx,ny,cur+1));
				}
			}
		}
	}
	dp[x][y] = res;
	return res;
}
int main(int argc, char const *argv[])
{
	vector<vector<int>> dp(m.size()+1,vector<int>(m[0].size(),-1));
	// for(int j=0;j<m[0].size();j++){
	// 	dp[m.size()-1][j] = m[m.size()-1][j] == 'D'? 0:1;
	// }
	// for(int i=m.size()-1;i>=0;i--){
	// 	for(int j=0;j<m[0].size();j++){
	// 		if(m[i][j] == '*'){
	// 			dp[i][j] = min(dp[i][j+1], dp[i][j-1], dp[i+1][j])+1
	// 		}
	// 		else if(m[i][j]=='L'){
	// 			dp[i][j] = min(dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j-1]);
	// 		}
	// 		else if(m[i][j]=='R'){
	// 			dp[i][j] = min(dp[i+1][j]+1,dp[i][j+1],dp[i][j-1]+1);
	// 		}
	// 		else if(m[i][j]=='D'){
	// 			dp[i][j] = min(dp[i+1][j],dp[i][j+1]+1,dp[i][j-1]+1);
	// 		}
	// 	}
	// }
	return 0;
}



