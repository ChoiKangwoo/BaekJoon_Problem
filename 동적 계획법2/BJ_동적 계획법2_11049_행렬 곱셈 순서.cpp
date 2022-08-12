#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_VALUE = 2147483646;
int r[500];		// ��Ŀ��� ���� ũ�� ����
int c[500];		//��Ŀ��� ���� ũ�� ����
int memory[500][500];	//start~end ������� �ʿ��� ���� Ƚ���� ����(�ּڰ�)


int dp(int start, int end)
{
	if (start == end)		//������ ũ�Ⱑ 1�϶� �� �ɰ� �� �ִ� ����� �����Ƿ� 0 ��ȯ
		return 0;

	if (memory[start][end] != MAX_VALUE)	return  memory[start][end];		//memory�� ����Ǿ� �ִ� ���� ������ �ٷ� ��ȯ�Ѵ�.


	for (int i = start; i < end; i++)
		//��� ������ Ƚ���� ����ϴ� ��ȭ���̴�.
		//��ȭ���� ���� memory�� �ּڰ��� ã�´�.
		memory[start][end] = min(memory[start][end], dp(start, i) + dp(i + 1, end) + r[start] * c[i] * c[end]);

	//���� memory ���� ��ȯ�Ѵ�.
	return memory[start][end];

}

void solve(int N)
{
	//����� ũ�Ⱑ 1�� �־����� ���� 0�� ��ȯ�Ѵ�.
	if (N == 1)
	{
		cout << '0';
		return;
	}

	//�� ���
	cout << dp(0, N - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//memory ������ ��� MAX_VALUE�� �ʱ�ȭ ��Ų��.
	fill_n(&memory[0][0], 500 * 500, MAX_VALUE);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> r[i] >> c[i];

	solve(N);

}