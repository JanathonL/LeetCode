#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100;
bool vst[maxn][maxn]; // 访问标记
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // 方向向量
 
struct State // BFS 队列中的状态数据结构
{
	int x,y; // 坐标位置
	int Step_Counter; // 搜索步数统计器
};
 
State a[maxn];
 
boolCheckState(State s) // 约束条件检验
{
	if(!vst[s.x][s.y] && ...) // 满足条件		
		return 1;
	else // 约束条件冲突
	return 0;
}
 
void bfs(State st)
{
	queue <State> q; // BFS 队列
	State now,next; // 定义2 个状态，当前和下一个
	st.Step_Counter=0; // 计数器清零
	q.push(st); // 入队	
	vst[st.x][st.y]=1; // 访问标记
	while(!q.empty())
	{
		now=q.front(); // 取队首元素进行扩展
		q.pop(); // 队首元素出队
		if(now==G) // 出现目标态，此时为Step_Counter 的最小值，可以退出即可
		{
			...... // 做相关处理
			return;
		}
		for(int i=0;i<4;i++)
		{
			next.x=now.x+dir[i][0]; // 按照规则生成	下一个状态
			next.y=now.y+dir[i][1];
			next.Step_Counter=now.Step_Counter+1; // 计数器加1
			if(CheckState(next)) // 如果状态满足约束条件则入队
			{
				q.push(next);
				vst[next.x][next.y]=1; //访问标记
			}
		}
		
	}
 return;
}
 
int main()
{
......
 return 0;
}
