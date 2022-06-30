#include <iostream>
#include<vector>

using namespace std;
int arr[100000];
int index = 0;

int main()
{
	int K;
	cin >> K;

	int sum = 0;

	while (K--)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			arr[index - 1] = 0;
			index--;
		}
		else
		{
			arr[index] = n;
			index++;
		}
	}
	for (int i = 0; i < index; i++)
		sum += arr[i];

	cout << sum;

}