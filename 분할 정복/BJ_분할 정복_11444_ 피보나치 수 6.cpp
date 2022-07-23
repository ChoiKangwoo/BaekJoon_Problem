#include <iostream>
#include <vector>

using namespace std;

const unsigned int MOD = 1000000007;	//��ⷯ ���꿡 �ʿ��� ���

vector <vector<long long>> M_D(vector<vector<long long>> A, vector<vector<long long>> B)	//2*2 ��İ� �Լ�
{
	vector <vector<long long>> C(2, vector<long long>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			long long sum = 0;
			for (int k = 0; k < 2; k++)
				sum += (A[i][k] * B[k][j]) % MOD;	//��ⷯ ����
			C[i][j] = sum % MOD;	//��ⷯ ����
		}

	return C;
}

vector <vector<long long>> fibonacci(long long n, vector <vector<long long>> C)	//�Ǻ���ġ ���ϴ� �Լ�
{
	//�ŵ����� �˰����� �̿��� ���� �����Ѵ�.
	if (n == 1)
		return C;

	vector <vector<long long>> temp = fibonacci(n / 2, C);

	if (n % 2)
		return M_D(M_D(temp, temp), C);

	else
		return M_D(temp, temp);


}

int main()
{
	long long n;
	cin >> n;

	//��İ��� �̿��� �Ǻ���ġ������ ���Ϸ���  {1,1},{1,0} 2*2 ����� �ŵ������� �̿��ؾ� �Ѵ�.
	vector <vector<long long>>A(2, vector<long long>(2, 1));
	A[1][1] = 0;


	vector<vector<long long>> ans = fibonacci(n, A);
	/*
	����� �ŵ����� ������ �����
	ans[0][0] = n+1 ��° �Ǻ���ġ ��
	ans[0][1], ans[1][0] = n ��° �Ǻ���ġ ��
	ans[1][1] = n-1 ��° �Ǻ���ġ �� �̴�.
	*/

	cout << ans[1][0];



}