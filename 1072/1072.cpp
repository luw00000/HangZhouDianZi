#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

class Point
{
	public:
		int time;
		int x, y;
		int count;
};

int n, m, startx, starty;
int map[9][9];
//定义方向，上下左右 
int direction[4][2] = {1, 0, -1, 0, 0, 1,0, -1};

int bfs()
{
	int i;
	int tx, ty;
	//定义队列 
	queue<Point> que;
	while(!que.empty())
	{
		que.pop();
	}
	//记录起始值 
	Point pt, temp;
	pt.x = startx;
	pt.y = starty;
	pt.time = 6;
	pt.count = 0;
	que.push(pt);
	while(!que.empty())
	{
		//获得列首元素 
		temp = que.front();
		//弹出列首元素 
		que.pop();
		//摘到出口则退出 
		if(map[temp.x][temp.y] == 3)
		{
			return temp.count;
		}
		//时间为1没到终点则出不去 
		if(temp.time == 1)
		{
			continue;
		}
		for(i = 0; i < 4; i++)
		{
			tx = temp.x + direction[i][0];
			ty = temp.y + direction[i][1];
			
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || map[tx][ty] == 0)
			{
				continue;
			}
			pt.x = tx;
			pt.y = ty;
			pt.count = temp.count + 1;
			pt.time = temp.time - 1;
			//引爆，重置时间 
			if(map[tx][ty] == 4)
			{
				pt.time = 6;
				map[tx][ty] = 0;
			}
			//入队列 
			que.push(pt);
		}
	}
	return -1;
}

int main()
{
	int t, j, k;
	while(scanf("%d", &t) != EOF)
	{
		while(t--)
		{
			scanf("%d %d", &n, &m);
			for(j = 0; j < n; j++)
			{
				for(k = 0; k < m; k++)
				{
					scanf("%d", &map[j][k]);
					if(map[j][k] == 2)
					{
						startx = j;
						starty = k;
					}
				}
			}
			int res = bfs();
			cout << res << endl;
		}
	}
	return 0;
}
