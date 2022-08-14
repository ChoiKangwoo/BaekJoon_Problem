#include <iostream>
#include <algorithm>

using namespace std;


int memory[2000][2000];
int arr[2000];

int palindrome(int start, int end)
{

	if (memory[start][end] != -1)
		return memory[start][end];


	if (arr[start] != arr[end])
		memory[start][end] = 0;
	else
	{
		memory[start][end] = 1;
		if (start + 1 <= end - 1)
			memory[start][end] = palindrome(start + 1, end - 1);
	}

	return memory[start][end];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	fill_n(&memory[0][0], 2000 * 2000, -1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int M;
	cin >> M;
    
    int s,e;
	for (int j = 0; j < M; j++)
    {
        cin >> s >> e;
		cout << palindrome( s-1, e-1) << '\n';
    }

}