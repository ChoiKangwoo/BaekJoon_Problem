#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[1001];
int visited[10001];


void dfs(int V)
{
	if (visited[V])
		return;

	visited[V] = true;

	cout << V << ' ';

	for (int i = 0; i < graph[V].size(); i++)
	{
		int x = graph[V][i];
		dfs(x);
	}

}

void bfs(int V)
{
	queue <int> q;
	q.push(V);

	visited[V] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << ' ';
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(V);
	cout << '\n';
	fill_n(&visited[0], 1001,0);
	bfs(V);




}