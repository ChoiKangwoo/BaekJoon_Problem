#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> &A, int low, int high,int n)
{
	if (A[(low + high) / 2] == n)
		return 1;
	if (low + 1 == high)
		if (A[low] != n || A[high] != n)
			return -1;

	if (A[(low + high) / 2] >= n)	//low 범위에 있음
		binary_search(A, low, (low + high) / 2, n);
	else
		binary_search(A, (low + high) / 2, high, n);

}

int main()
{
	int N;
	cin >> N;

	vector <int>A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int M;
	cin >> M;

	vector<int> B(M);
	for (int i = 0; i < M; i++)
		cin >> B[i];

	while (M--)
	{
		cout << binary_search(A, 0, A.size(), B[N - M]) << '\n';

	}
}