#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int maze[100][100];
int visit[100][100];
int min_route[100][100];
queue<pair<int, int>> q;
int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };


void bfs(int x, int y)
{
	visit[y][x] = 1;
	q.push(make_pair(y, x));
	min_route[y][x]++;

	while (!q.empty())
	{
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = ty + mov[i][0];
			int nx = tx + mov[i][1];

			if (0 <= ny && ny < N && 0 <= nx && nx < M)
				if (maze[ny][nx] == 1 && visit[ny][nx] == 0)
				{
					visit[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					min_route[ny][nx] = min_route[ty][tx] + 1;
				}
		}
}
}



int main()
{
	scanf("%d%d", &N, &M);

	fill_n(&visit[0][0], 100 * 100, 0);
	fill_n(&min_route[0][0], 100 * 100, 0);

	for (int i = 0; i < N; i++)
		for (int k = 0; k < M; k++)
			scanf("%1d", &maze[i][k]);

	bfs(0, 0);

	printf("%d", min_route[N-1][M-1]);

}