#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100000;
int heap[MAX_SIZE] = { 0 };
int node = 0;
vector<int> ans;

void add(int x);
void print_out();

int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0)
			add(x);
		else if (x == 0)
			print_out();
	}

	for (int j = 0; j < ans.size(); j++)
		cout << ans[j] << '\n';
}

void add(int x)
{
	heap[++node] = x;
	int i = node;
	while (i > 1)
	{
		if (heap[i] > heap[i / 2])
		{
			heap[i] = heap[i / 2];
			heap[i / 2] = x;
			i /= 2;
		}

		else
			break;
	}
}

void print_out()
{
	if (heap[1] == 0)
		ans.push_back(0);
	else
		ans.push_back(heap[1]);

	int temp = heap[node];
	heap[1] = temp;
	heap[node--] = 0;

	int parent = 1;
	int child = 2;

	while (child <= node)
	{
		if (heap[child] < heap[child + 1] && child < node)
			child++;
		if (heap[child] <= heap[parent])
			break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;

}