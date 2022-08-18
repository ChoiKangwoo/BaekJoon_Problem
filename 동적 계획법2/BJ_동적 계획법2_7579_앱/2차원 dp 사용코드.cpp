#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cache[101][10001];
int m[101];
int c[101];

void knapsack()
{
	int size = 0;
	for (int i = 1; i <= N; i++)
		size += c[i];

	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= size; j++)
		{
			//cache[i][j] : i 번째 앱까지 탐색했을 때 j 비용을 사용하여 얻을 수 있는 최대 메모리
			
			//점화식: i-1 번째 앱까지 확인한 cost-c[i] 의 메모리에 m[i]를 더한다. (max 함수 필요없음, cache[i][j]는 0이다.)
			if (j - c[i] >= 0)
				cache[i][j] = cache[i - 1][j - c[i]] + m[i];

			//이때 cache[i][j]는 0이 아니기 때문에 max 함수 필요함
			cache[i][j] = max(cache[i][j], cache[i - 1][j]);
		}

	//N 번째 앱까지 확인 한 결과 M 메모리 이상으로 제거한 비용들중 최소 비용을 출력
	for(int i=0;i<=size;i++)
		if (cache[N][i] >= M)
		{
			cout << i;
			return;
		}

}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> m[i];	//index 번째 앱의 메모리 크기를 저장

	for (int i = 1; i <= N; i++)
		cin >> c[i];	//index 번째 앱의 비활성화 비용을 저장

	knapsack();

}