#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];	//�׷��� ����
int visited[100001];	//�湮�� ��� �����

int ans[100001];	//�� ������ �湮�� ������ ���
int c = 0;	//���� ����� ���� ī��Ʈ ����

void dfs(int x)
{
	//�湮�� ����� �ִٸ� �������
	if (visited[x])
		return;

	//���� ������ �湮�����Ƿ� ����� �����.
	visited[x] = true;

	//������ �湮�� ������ ����Ѵ�.
	ans[x] = ++c;

	for (int i = 0; i < graph[x].size(); i++)
	{
		//���� ������ ����� �ٸ� �������� ������������ Ž���Ѵ�.
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

	//������������ Ž���ϱ����� �������ش�.
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	
	//���� ���� R�� ���� Ž������
	dfs(R);

	//���� ���
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}