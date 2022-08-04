#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;
vector<int>ans;
int last = 0;

void add_to_heap(int x)
{
	int index = ++last;
	while(index!=1&&x<heap[index/2])
	{
		heap[index] = heap[index / 2];
		index/= 2;
	}

}

void del_heap()
{
	if (last == 0)
	{
		ans.push_back(0);
		return;
	}
	else
		ans.push_back(heap[1]);

	int temp = heap[last];
	heap[last--] = 0;
	heap[1] = temp;

	int parent = 1;
	int child = 2;
	while (child<=last)
	{
		if (heap[child] > heap[child + 1] && child < last)
			child++;
		if (temp <= heap[child] )
			break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	
}

int main()
{
	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0)
			add_to_heap(x);
		else		//x가 0인경우
			del_heap();
	}

	for (int j =0 ; j < ans.size(); j++)
		cout << ans[j] << '\n';
}