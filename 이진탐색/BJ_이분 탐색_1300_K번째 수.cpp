#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
������ �� mid ���� �۰ų� ���� ���� ������ ���� k�� ���� �Ű����� Ž���� �ϴ� �˰���
����� ���ҵ��� i*j���� �̷���� �ֱ� ������ i�� ����̴�. ���� mid/i �� ����� i �࿡���� mid ���� ���� ������ �����̴�.
������ mid/i�� N ���� ū ���� �ش� ���� ��� ���Ұ� mid ������ �۴ٴ� �ǹ��̱� ������ N���� �ȴ�.
���� i ���� mid ���� ���� ���ҵ��� ������ min(mid/i,N)
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