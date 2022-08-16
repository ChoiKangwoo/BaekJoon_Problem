#include <iostream>
#include <algorithm>

using namespace std;

int coin[100];
int memory[10001];
int n, k;

void solve()
{

	//0의 가치를 만들어내는 경우의 수는 오직 한 개(base condition)
	memory[0] = 1;

	//memory[j] 의 경우의 수는 memory[j-coin[i]]의 경우의 수들을 더해준 것과 같다.
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			memory[j] += memory[j - coin[i]];

	//정답 출력
	cout << memory[k];


}
int main()
{

	cin >> n >> k;

	fill_n(&memory[0], 10000, 0);

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	solve();

}