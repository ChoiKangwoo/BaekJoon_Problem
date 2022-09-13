#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int I;
int sy, sx;
int dy, dx;

int visited[300][300];
int co[300][300];

int moving[8][2] = { {2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2} };

void bfs(int srcx,int srcy)
{
	queue<pair<int, int>> q;
	q.push(make_pair(srcy, srcx));

	int y = q.front().first;
	int x = q.front().second;

	visited[y][x] = true;

	while (!q.empty())
	{
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();
		
		if (ty == dy && tx == dx)
			return;

		int ny, nx;
		for (int i = 0; i < 8; i++)
		{
			ny = ty + moving[i][0];
			nx = tx + moving[i][1];

			if(0<=ny&&ny<I&&0<=nx&&nx<I)
				if (visited[ny][nx] == false)
				{
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					co[ny][nx] = co[ty][tx] + 1;
						
				}


		}

	}


}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		fill_n(&visited[0][0], 300 * 300, 0);
		fill_n(&co[0][0], 300 * 300, 0);
		
		cin >> I;

		
		cin >> sx >> sy;

		cin >> dx >> dy;

		if (sx != dx || sy != dy)
			bfs(sx, sy);

		cout << co[dy][dx]<<'\n';



	}





}