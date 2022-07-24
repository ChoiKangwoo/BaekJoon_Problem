#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> &A, int n)
{
	int low = 0;
	int high = A.size() - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (n < A[mid])
			high = mid - 1;
		else if (n > A[mid])
			low = mid + 1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	cin.tie(NULL);
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
	int k = 0;
	while (M--)
	{
		cout << binary_search(A, B[k++]) << '\n';

	}
}