#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];	//그래프 선언
int visited[100001];	//방문한 기록 남기기

int ans[100001];	//각 정점이 방문된 순서를 기록
int c = 0;	//순서 기록을 위한 카운트 변수

void dfs(int x)
{
	//방문한 기록이 있다면 재귀종료
	if (visited[x])
		return;

	//현재 정점을 방문했으므로 기록을 남긴다.
	visited[x] = true;

	//정점에 방문한 순서를 기록한다.
	ans[x] = ++c;

	for (int i = 0; i < graph[x].size(); i++)
	{
		//현재 정점에 연결된 다른 정점들을 오름차순으로 탐색한다.
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

	int u, v ;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//오름차순으로 탐색하기위해 정렬해준다.
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	
	//시작 정점 R로 부터 탐색시작
	dfs(R);

	//정답 출력
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}