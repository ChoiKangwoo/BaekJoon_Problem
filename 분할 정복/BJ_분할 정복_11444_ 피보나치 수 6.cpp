#include <iostream>
#include <vector>

using namespace std;

const unsigned int MOD = 1000000007;

vector <vector<unsigned int>> M_D(vector<vector<unsigned int>> A, vector<vector<unsigned int>> B)
{
	vector <vector<unsigned int>> C(2, vector<unsigned int>(2));
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++)
		{
			int sum = 0;
			for (int k = 0; k < 2; k++)
				sum += (A[i][k] * B[k][j])%MOD;
			C[i][j] = sum%MOD;
		}

	return C;
}

vector <vector<unsigned int>> fibonacci(long long n,vector <vector<unsigned int>> C)
{
	if (n == 1)
		return C;
	
	vector <vector<unsigned int>> temp = fibonacci(n/2,C);

	if (n % 2)
		return M_D(M_D(temp,temp),C);
	else
		return M_D(temp, temp);
	
}

int main()
{
	long long n;
	cin >> n;

	vector <vector<unsigned int>>A(2, vector<unsigned int>(2, 1));
	A[1][1] = 0;
	
	vector<vector<unsigned int>> ans = fibonacci(n, A);

	cout << ans[0][1]%MOD;



}