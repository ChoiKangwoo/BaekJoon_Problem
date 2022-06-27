#include <iostream>
#include <ctime>
using namespace std;

void quick_sort(int arr[], int start, int end);
int main()
{
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	quick_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';



}

void quick_sort(int arr[], int start, int end)
{

	if (start >= end)
		return;

	int left = start;
	int right = end;
	int pivot_index = start + rand() % (end - start);
	int pivot = arr[pivot_index];      //값을 지정해주는 이유:변수 조작으로 생길 수 있는 에러 방지
	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;

		if (left <= right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++; right--;
		}


	}

	quick_sort(arr, start, right);
	quick_sort(arr, left, end);







}
