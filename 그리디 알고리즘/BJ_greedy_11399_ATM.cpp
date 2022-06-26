#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Quicksort(vector<int> &P, int first, int last);

int main()
{

	int N;				//N ���� �����
	cin >> N;

	vector<int> P(N);			//���� �����ϴµ� �ɸ��� �ð��� �����ϴ� �迭 P
	for (int i = 0; i < N; i++)
		cin >> P[i];

	//quick ������ �̿��� ���� ���� ����
	Quicksort(P, 0, N-1);

	//�ּڰ� ���ϱ�
	int sum = 0;

	//0~i ������ ��=i ��° ����� �����ϱ���� �ɸ��� �ð�
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			sum += P[j];
			
	cout << sum;




}

//quick ����(�������� ����)
void Quicksort(vector<int> &P, int first,int last)
{
	if (first >= last)
		return;

	int left = first;
	int right = last;
	int pivot_index = first + rand() % (last - first);
	int pivot = P[pivot_index];

	while (left < right)
	{
		while (P[left] < pivot)
			left++;
		while (P[right] > pivot)
			right--;

		if (left <= right)
		{
			int temp = P[left];
			P[left] = P[right];
			P[right] = temp;
			left++; right--;
		}

	}

	Quicksort(P, first, right);
	Quicksort(P, left, last);
}