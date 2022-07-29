#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
임의의 수 mid 보다 작거나 같은 수의 개수를 세어 k와 비교해 매개변수 탐색을 하는 알고리즘
행렬의 원소들은 i*j으로 이루어져 있기 때문에 i의 배수이다. 따라서 mid/i 의 결과가 i 행에서의 mid 보다 작은 수들의 개수이다.
하지마 mid/i가 N 보다 큰 경우는 해당 행의 모든 원소가 mid 값보다 작다는 의미이기 때문에 N개가 된다.
따라서 i 행의 mid 보다 작은 원소들의 개수는 min(mid/i,N)
*/

int parameter_search(int start, int end, int &k, int &N)
{
	int mid = (start + end) / 2;

	int count = 0;
	for (int i = 1; i <= N; i++)
		count += min(mid / i, N);

	if (start >= end)
		if (count < k)
			return mid + 1;
		else
			return mid;

	if (count < k)
		return parameter_search(mid + 1, end, k, N);
	else
		return parameter_search(start, mid - 1, k, N);


}
int main()
{

	int N, k;
	cin >> N >> k;
	
	int start = 1;
	int end = (int)min((long long)1000000000,(long long)N*(long long)N);

	cout << parameter_search(start, end, k, N);

}