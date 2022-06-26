#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
void Quicksort(vector<int> &start,vector<int> &end, int first, int last);

//시간초과 나중에 다시 풀것

int main()
{
	
	int N;			//N 개의 회의수
	cin >> N;		//N 입력받기

	vector <int> start(N);			//회의 시작시간 입력받기
	vector<int> end(N);			//회의 끝나는 시간 입력받기

	//회의의 시작시간과 끝나는 시간 입력받기
	for (int i = 0; i < N; i++)
	{
		cin >> start[i] >> end[i];			
	}

	


	//end 와 start 배열을 end 값 기준으로 오름차순정렬을 한다.
	
	Quicksort(start, end, 0, N - 1);

	//start 배열중 제일 큰 값 찾기
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (start[max] < start[i])
			max = i;
	}

	//end 배열중 제일 큰 값 찾기
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
		

		if (end[m] >start[max] || m==N-1)			//end[m] 보다 큰 start 값이 없으면 더이상의 회의 없다고 간주
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