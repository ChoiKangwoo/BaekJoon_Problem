#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이진 탐색 알고리즘으로 L 원소들중에서 A[i] 가 들어갈 자리를 찾아 반환한다.
//A[i] 보다 크거나 같은 자리를 반환한다.
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

	//L의 마지막 원소와 A[i]를 비교하여 A[i]가 더 크면 L 에 push_back을 한다.
	for (int i = 0; i < A.size(); i++)
		if (L.back() < A[i])
			L.push_back(A[i]);
	//아니라면 A[i] 가 들어갈 자리를 찾아 L[alt]를 A[i]으로 대체한다.
		else
		{
			int alt = binary_search(L, A[i], 0, L.size() - 1);
			//L[alt]보다 A[i]가 작을 경우에만 바꾼다.
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