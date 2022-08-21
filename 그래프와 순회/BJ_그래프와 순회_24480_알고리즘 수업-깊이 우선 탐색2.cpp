#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int ans[100001];
int c = 0;

void dfs(int x)
{
	if (visited[x])
		return;

	visited[x] = true;
	
	ans[x] = ++c;

	for (int i = graph[x].size() - 1; i >= 0; i--)
	{
		int y = graph[x][i];
		dfs(y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';


}