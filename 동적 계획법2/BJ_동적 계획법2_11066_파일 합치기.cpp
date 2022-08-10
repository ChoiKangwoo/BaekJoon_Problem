#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long file_combine(vector<int> &A, int start, int end,long long sum)
{
	if (start + 1 == end)	//구간 원소가 두 개인 경우
		return A[start] + A[end];
	if (start == end)
		return 0;
	int left = start-1;
	int right = end+1;
	
	long long half = sum / 2;
	long long sl = 0;
	long long sr = 0;
	long long cost = 0;
	while (sl < half)
		sl += A[++left];
	

	while (sr < half)
		sr += A[--right];


	if (left == right)
	{
		if (sl < sr)
			sr -= A[right++];
		else
			sl -= A[left--];
	}

	cost += sl + file_combine(A, start, left, sl);
	cost += sr + file_combine(A, right, end, sr);

	return cost;

}

int main()
{
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;
		long long sum = 0;
		vector<int> A(K);
		for (int i = 0; i < K; i++)
		{
			cin >> A[i];
			sum += A[i];
		}

		cout << file_combine(A, 0, K - 1, sum) << '\n';
	}

}