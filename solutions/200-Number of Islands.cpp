// 200. Number of Islands
// （1） DFS Time:O(n) 
// 每个区域设置一下visit，然后染色遍历就好了，每次都把所有能染色的区域染色，之后进行下一次染色 cnt++, return cnt
// （2） 并查集
// 先对所有的1都计数cnt++, 然后union的时候对每个1都上下左右判断合并，如果father不相等就合并而且cnt--, 最后输出cnt
// 这里有个2维映射到1维的编码过程  i*col + j注意 横坐标是乘以col而不是row。

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        cnt = 0;
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        father = vector<int>(n*m,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    
                    int tmp = i*m+j;
                    // cout<<tmp<<endl;
                    father[tmp]=tmp;
                    cnt++;
                }
            }
        }
        
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    // cout<<"i:"<<i<<" j:"<<j<<endl;
                    for(auto d:dir){
                        int x = i+d[0];
                        int y = j+d[1];
                        if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]=='1'){
                            // cout<<"i:"<<i<<" j:"<<j<<endl;
                            int t1,t2;
                            t1 = i*m+j;
                            t2 = x*m+y;
                            connect(t1,t2);
                        }
                    }
                }
            }
        }
        return cnt;
        
    }
    int find(int a){
        if(a!=father[a]){
            return find(father[a]);
        }
        return a;
    }
    void connect(int a, int b){
        
        a = find(a);
        b = find(b);
        if(a==b) return;
        father[a]=b;
        cnt--;
    }
    
private:
    int cnt;
    vector< int > father;
};
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         cnt = 0;
//         int n = grid.size();
//         if(n==0) return 0;
//         int m = grid[0].size();
//         vector<vector<bool>> visit(n,vector<bool>(m,false));
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(!visit[i][j]&&grid[i][j]=='1'){
//                     cnt++;
//                     dfs(grid,visit,i,j);
//                 }
//             }
//         }
//         return cnt;
//     }
//     void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y){
//         // cout<<"x:"<<x<<" y:"<<y<<" cnt:"<<cnt<<endl;
//         if(x>=grid.size()||y>=grid[0].size()||x<0||y<0) return;
//         if(!visit[x][y]){
//             visit[x][y]=1;
//         }
//         else{
//             return ;
//         }
//         if(grid[x][y]=='0') return;
        
//         grid[x][y]=cnt+'0';
//         dfs(grid,visit,x+1,y);
//         dfs(grid,visit,x-1,y);
//         dfs(grid,visit,x,y+1);
//         dfs(grid,visit,x,y-1);
//     }
// private:
//     int cnt;
// };