#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cache[10001];
int m[100];
int c[100];

void knapsack()
{
	int size = 0;
	//size: 모든 앱의 비활성화 비용의 합을 구한다.( 계산 범위를 정하기 위한 변수)
	for (int i = 0; i < N; i++)
		size += c[i];

	for (int i = 0; i < N; i++)
		for (int j = size; j >= c[i]; j--)
			//점화식: 같은 삭제비용으로 가능한 많은 메모리를 비운다. 
			//기존 cost로 제거한 메모리와 현재 cost-c[i]의 메모리에서 c[i]비용을 더쓰고 m[i]을 추가로 제거한 메모리와 비교를 한다. (두 계산식다 같은 비용을 쓴 것이다.)
			cache[j] = max(cache[j], cache[j - c[i]] + m[i]);

	for (int i = 0; i <= size; i++)
		if (cache[i] >= M)
		{
			//최소 제거비용으로 조건에 맞는 메모리를 제거했을경우 출력
			cout << i;
			return;
		}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> m[i];	//index 번째 앱의 메모리 크기를 저장

	for (int i = 0; i < N; i++)
		cin >> c[i];	//index 번째 앱의 비활성화 비용을 저장

	knapsack();

}