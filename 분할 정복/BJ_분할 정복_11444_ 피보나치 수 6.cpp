#include <iostream>
#include <vector>

using namespace std;

const unsigned int MOD = 1000000007;	//모듈러 연산에 필요한 상수

vector <vector<long long>> M_D(vector<vector<long long>> A, vector<vector<long long>> B)	//2*2 행렬곱 함수
{
	vector <vector<long long>> C(2, vector<long long>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			long long sum = 0;
			for (int k = 0; k < 2; k++)
				sum += (A[i][k] * B[k][j]) % MOD;	//모듈러 연산
			C[i][j] = sum % MOD;	//모듈러 연산
		}

	return C;
}

vector <vector<long long>> fibonacci(long long n, vector <vector<long long>> C)	//피보나치 구하는 함수
{
	//거듭제곱 알고리즘을 이용해 분할 정복한다.
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

	//행렬곱을 이용해 피보나치수열을 구하려면  {1,1},{1,0} 2*2 행렬의 거듭제곱을 이용해야 한다.
	vector <vector<long long>>A(2, vector<long long>(2, 1));
	A[1][1] = 0;


	vector<vector<long long>> ans = fibonacci(n, A);
	/*
	행렬의 거듭제곱 연산의 결과는
	ans[0][0] = n+1 번째 피보나치 수
	ans[0][1], ans[1][0] = n 번째 피보나치 수
	ans[1][1] = n-1 번째 피보나치 수 이다.
	*/

	cout << ans[1][0];



}