#include <iostream>
#include <algorithm>

using namespace std;

int T;
int M, N, K;

int graph[50][50];
int visit[50][50];
int m[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int num;

void dfs(int x,int y)
{
	if (visit[y][x])
		return;

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + m[i][0];
		int ny = y + m[i][1];

		if (0 <= ny && ny < N && 0 <= nx && nx < M)
			if (graph[ny][nx] == 1)
				dfs(nx, ny);
	}



}
void solve()
{
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && graph[i][j] == 1)
			{
				dfs(j, i);
				num++;
			}
		}

	cout << num << '\n';
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--)
	{
		num = 0;
		fill_n(&graph[0][0], 50 * 50, 0);
		fill_n(&visit[0][0], 50 * 50, 0);

		cin >> M >> N >> K;

		int X, Y;
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			graph[Y][X] = 1;
		}

		solve();


	}

}