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
			//cache[i][j] : i ��° �۱��� Ž������ �� j ����� ����Ͽ� ���� �� �ִ� �ִ� �޸�
			
			//��ȭ��: i-1 ��° �۱��� Ȯ���� cost-c[i] �� �޸𸮿� m[i]�� ���Ѵ�. (max �Լ� �ʿ����, cache[i][j]�� 0�̴�.)
			if (j - c[i] >= 0)
				cache[i][j] = cache[i - 1][j - c[i]] + m[i];

			//�̶� cache[i][j]�� 0�� �ƴϱ� ������ max �Լ� �ʿ���
			cache[i][j] = max(cache[i][j], cache[i - 1][j]);
		}

	//N ��° �۱��� Ȯ�� �� ��� M �޸� �̻����� ������ ������ �ּ� ����� ���
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
		cin >> m[i];	//index ��° ���� �޸� ũ�⸦ ����

	for (int i = 1; i <= N; i++)
		cin >> c[i];	//index ��° ���� ��Ȱ��ȭ ����� ����

	knapsack();

}