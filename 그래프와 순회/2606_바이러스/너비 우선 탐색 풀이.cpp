#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> graph[101];
int visited[101];
int ans = 0;

void bfs(int R)
{
	queue <int> q;
	q.push(R);

	visited[R] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		ans++;

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}

		}
	}

}
int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(1);

	cout << ans;

}