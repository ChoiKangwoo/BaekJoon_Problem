#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> graph[101];
int visited[101];
int ans = 0;

void dfs(int x)
{
	if (visited[x])
		return;

	visited[x] = true;

	if (x != 1)
		ans++;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		dfs(y);
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
	dfs(1);

	cout << ans;

}