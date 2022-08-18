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
	//size: ��� ���� ��Ȱ��ȭ ����� ���� ���Ѵ�.( ��� ������ ���ϱ� ���� ����)
	for (int i = 0; i < N; i++)
		size += c[i];

	for (int i = 0; i < N; i++)
		for (int j = size; j >= c[i]; j--)
			//��ȭ��: ���� ����������� ������ ���� �޸𸮸� ����. 
			//���� cost�� ������ �޸𸮿� ���� cost-c[i]�� �޸𸮿��� c[i]����� ������ m[i]�� �߰��� ������ �޸𸮿� �񱳸� �Ѵ�. (�� ���Ĵ� ���� ����� �� ���̴�.)
			cache[j] = max(cache[j], cache[j - c[i]] + m[i]);

	for (int i = 0; i <= size; i++)
		if (cache[i] >= M)
		{
			//�ּ� ���ź������ ���ǿ� �´� �޸𸮸� ����������� ���
			cout << i;
			return;
		}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> m[i];	//index ��° ���� �޸� ũ�⸦ ����

	for (int i = 0; i < N; i++)
		cin >> c[i];	//index ��° ���� ��Ȱ��ȭ ����� ����

	knapsack();

}