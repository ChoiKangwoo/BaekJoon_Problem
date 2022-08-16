#include <iostream>
#include <algorithm>

using namespace std;

int coin[100];
int memory[10001];
int n, k;

void solve()
{

	//0�� ��ġ�� ������ ����� ���� ���� �� ��(base condition)
	memory[0] = 1;

	//memory[j] �� ����� ���� memory[j-coin[i]]�� ����� ������ ������ �Ͱ� ����.
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			memory[j] += memory[j - coin[i]];

	//���� ���
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