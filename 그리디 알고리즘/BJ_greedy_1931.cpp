#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
void Quicksort(vector<int> &start,vector<int> &end, int first, int last);

//�ð��ʰ� ���߿� �ٽ� Ǯ��

int main()
{
	
	int N;			//N ���� ȸ�Ǽ�
	cin >> N;		//N �Է¹ޱ�

	vector <int> start(N);			//ȸ�� ���۽ð� �Է¹ޱ�
	vector<int> end(N);			//ȸ�� ������ �ð� �Է¹ޱ�

	//ȸ���� ���۽ð��� ������ �ð� �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		cin >> start[i] >> end[i];			
	}

	


	//end �� start �迭�� end �� �������� �������������� �Ѵ�.
	
	Quicksort(start, end, 0, N - 1);

	//start �迭�� ���� ū �� ã��
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (start[max] < start[i])
			max = i;
	}

	//end �迭�� ���� ū �� ã��
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (end[temp] < end[i])
			temp = i;
	}




	int count = 1;
	int m=0;

	

	while (1)
	{
	

		for (int i = m; i < N; i++)
		{
			if (end[m] == start[i]&&end[m]==end[i])
				count++;
			if (end[m] == start[m]&&m==i)
				count--;

			if (end[m] <=start[i]&&end[m]<end[i])
			{
				m = i;
				count++;
				break;
			}

		}
		

		if (end[m] >start[max] || m==N-1)			//end[m] ���� ū start ���� ������ ���̻��� ȸ�� ���ٰ� ����
			break;
		

	}
	

	cout << count;

	
	

}


void Quicksort(vector<int> &start, vector<int> &end, int first, int last)
{
	if (first >= last)
		return;

	int left = first;
	int right = last;
	int pivot_index = first + rand() % (last - first);
	int pivot = end[pivot_index];

	while (left < right)
	{
		while (end[left] < pivot)
			left++;
		while (end[right] > pivot)
			right--;

		if (left <= right)
		{
			int temp = end[left];
			end[left] = end[right];
			end[right] = temp;

			int temp2 = start[left];
			start[left] = start[right];
			start[right] = temp2;

			left++; right--;
		}

	}

	Quicksort(start, end, first, right);
	Quicksort(start, end, left, last);




}