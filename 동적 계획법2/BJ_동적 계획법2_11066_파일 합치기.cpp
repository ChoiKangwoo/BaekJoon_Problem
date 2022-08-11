#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memory[500][500];
int prefix_sum[500];
int cost[500];
const int temp = 999999999;	//����� ū ��

int dp(int start, int end)
{
	if (start == end)	//�����������: ����ũ�Ⱑ 1�� ���� �ش� ���� ���� �����Ƿ� �ٷ� return �Ѵ�.
		return cost[start];

	int& ret = memory[start][end];
	if (ret != -1)	return ret;		//memory�� �ҷ��ͼ� �̹� ���� ����Ǿ� ������ ������ ����ʿ���� �ٷ� return �Ѵ�.

	ret = temp;	//�ּҰ� �񱳸� ���� �ӽð� �ʱ�ȭ

	int sum;
	if (start != 0)
		sum = prefix_sum[end] - prefix_sum[start - 1];	// start~end �� �������� 0~end ������ - 0~(start-1) �������̴�.
	else
		sum = prefix_sum[end];	//start�� 0 �ϰ�� sum�� prefix_sum[end] �� �����ϴ�.

	for (int i = start; i < end; i++)
		ret = min(ret, dp(start, i) + dp(i + 1, end) + sum);	//������ ��ġ�� ���� ���� sum�� ���� ������ ��ġ�µ� �ʿ��� �� ����̴�.

	return ret;

}

void solve(int K)
{
	int ret = temp;

	//�������� �� ���� ��츦 ã�� ������ ret ���� �����ϸ鼭 ��������δ� �ּҰ��� ���Եȴ�.
	for (int i = 0; i < K - 1; i++)
		//���� ���Ϻ����� ���� ����Ѵ�. �� �ܰ迡���� sum ������ �ʿ� ����!! �̹� return ���� dp �� �ȿ� sum �� ����Ǿ� ����
		//sum1+sum2=sum
		ret = min(ret, dp(0, i) + dp(i + 1, K - 1));

	cout << ret << '\n';
}


int main()
{
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		memset(memory, -1, sizeof(memory)); //memory ����ִ� �۾�

		int K;
		cin >> K;

		for (int i = 0; i < K; i++)
			cin >> cost[i];

		for (int j = 0; j < K; j++)
		{
			if (j != 0)
				prefix_sum[j] = prefix_sum[j - 1] + cost[j];	//��ȭ��: 0~j ��° ���� ������ ��� ��= 0~j-1 ���� ��+j ��° ���� ���

			else
				prefix_sum[j] = cost[0];	//ù ���Ҵ� �������Ұ� �������� �����Ƿ� ���ܸ� �ξ� ���
		}

		solve(K);

	}

	return 0;
}