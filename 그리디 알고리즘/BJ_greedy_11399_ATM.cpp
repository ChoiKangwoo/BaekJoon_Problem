#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Quicksort(vector<int> &P, int first, int last);

int main()
{

	int N;				//N 명의 사람들
	cin >> N;

	vector<int> P(N);			//돈을 인출하는데 걸리는 시간을 저장하는 배열 P
	for (int i = 0; i < N; i++)
		cin >> P[i];

	//quick 정렬을 이용한 오름 차순 정렬
	Quicksort(P, 0, N-1);

	//최솟값 구하기
	int sum = 0;

	//0~i 까지의 합=i 번째 사람이 인출하기까지 걸리는 시간
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			sum += P[j];
			
	cout << sum;




}

//quick 정렬(오름차순 구현)
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