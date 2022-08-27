#include <iostream>
#include <algorithm>


using namespace std;

int N;
int graph[25][25];
int n[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int arrsize[313];

int cnt=2;


void dfs(int y,int x,int num)
{
	graph[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + n[i][0];
		int nx = x + n[i][1];

		if (0 <= ny && ny < N && 0 <= nx && nx < N)
			if (graph[ny][nx] == 1)
				dfs(ny, nx, num);
	}

}

void solve()
{
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1)
			{
				dfs(i, j, cnt++);
			}
		}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if (graph[i][j] > 1)
			{
				arrsize[graph[i][j] - 2]++;
			}

}

int main()
{
	cin >> N;


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &graph[i][j]);
		}

	solve();
	
	sort(arrsize, arrsize + cnt - 2);

	cout << cnt - 2 << '\n';
	for (int i = 0; i < cnt - 2; i++)
		cout << arrsize[i] << '\n';

	return 0;

}