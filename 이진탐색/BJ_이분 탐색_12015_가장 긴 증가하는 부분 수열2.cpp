#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� Ž�� �˰������� L ���ҵ��߿��� A[i] �� �� �ڸ��� ã�� ��ȯ�Ѵ�.
//A[i] ���� ũ�ų� ���� �ڸ��� ��ȯ�Ѵ�.
int binary_search(vector<int> &L, int A, int start, int end)
{
	int mid = (start + end) / 2;

	if (start >= end)
		if (L[mid] >= A)
			return mid;
		else
			return mid + 1;

	if (L[mid] >= A)
		return binary_search(L, A, start, mid - 1);
	else
		return binary_search(L, A, mid + 1, end);


}

int LIS(vector<int> &A)
{
	vector<int> L;
	L.push_back(A[0]);

	//L�� ������ ���ҿ� A[i]�� ���Ͽ� A[i]�� �� ũ�� L �� push_back�� �Ѵ�.
	for (int i = 0; i < A.size(); i++)
		if (L.back() < A[i])
			L.push_back(A[i]);
	//�ƴ϶�� A[i] �� �� �ڸ��� ã�� L[alt]�� A[i]���� ��ü�Ѵ�.
		else
		{
			int alt = binary_search(L, A[i], 0, L.size() - 1);
			//L[alt]���� A[i]�� ���� ��쿡�� �ٲ۴�.
			if (L[alt] > A[i])
				L[alt] = A[i];
		}

	return L.size();


}

int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << LIS(A);


}