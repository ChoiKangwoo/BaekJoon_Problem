#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1000][1000];
int visited[1000][1000];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int M, N;
int day = 0;
queue <pair<int,int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = y + d[i][0];
			int dx = x + d[i][1];

			if(0<=dx&&dx<M&& 0 <= dy && dy < N )
				if (visited[dy][dx] == -1 && arr[dy][dx] == 0)
				{
					visited[dy][dx] = visited[y][x]+1;
					arr[dy][dx] = true;
					q.push({ dy,dx });
				}
		}
	}
}


int  main()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push({ i,j });
			}
			else if (arr[i][j] == 0)
				visited[i][j] = -1;
		}

	bfs();

	int ans = visited[0][0];
	for (int i = 0; i < N; i++)
	{
		if (ans == -1)
			break;
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == -1)
			{
				ans = -1;
				break;
			}
			if (ans < visited[i][j])
				ans = visited[i][j];
		}
	}

		cout << ans;



}