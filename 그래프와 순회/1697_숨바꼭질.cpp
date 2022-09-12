#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int min_sec[100001];
int visited[100001];

//걸을 때 1초 후에 X+1 or X-1 위치
//순간이동 할 때 1초 후에 2*X 의 위치

void bfs(int x)
{
	
	min_sec[x]++;
	queue<int> q;

	q.push(x);
	visited[x] = true;

	while (!q.empty())
	{
		int y = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++)
		{
			int ny;
			if (i == 0)
				ny = y + 1;
			if (i == 1)
				ny = y - 1;
			if (i == 2)
				ny = y * 2;

			if(0<=ny&&ny<=100000)
				if (visited[ny] == false)
				{
					visited[ny] = true;
					q.push(ny);
					min_sec[ny] = min_sec[y] + 1;
				}

		}



	}



}


int main()
{
	int N, K;
	cin >> N >> K;

	fill_n(&visited[0], 100001, 0);
	fill_n(&min_sec[0], 100001, 0);

	bfs(N);

	cout << min_sec[K] - 1;



}