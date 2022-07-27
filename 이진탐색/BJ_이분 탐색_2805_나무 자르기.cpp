#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parameter_search(vector<int> &tree, int M, int start, int end)
{
	int mid = (start + end) / 2;

	long long high = 0;	//total high
	for (int i = 0; i < tree.size(); i++)
		if (tree[i] > mid)	//자르고자 하는 높이보다 큰 나무들만 잘라서 total high에 더해준다.
			high += tree[i] - mid;

	if (start >= end)
		if (high >= M)
			return mid;
		else
			return mid - 1;

	if (high >= M)
		return parameter_search(tree, M, mid + 1, end);
	else
		return parameter_search(tree, M, start, mid - 1);


}



int main()
{
	int N,M;
	cin >> N >> M;

	vector<int> tree(N);
	for (int i = 0; i < N; i++)
		cin >> tree[i];

	int start = 0;
	int end = 1000000000;

	cout << parameter_search(tree, M, start, end);

}