#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_VALUE = 2147483646;
int r[500];
int c[500];
int memory[500][500];	//start~end 행까지의 필요한 곱셈 횟수를 저장


int dp(int start,int end)
{
	if (start == end)
		return 0;
		
	int& temp = memory[start][end];	//temp 의 값은 곧 memory에 저장된다.
	if (temp != -1)	return temp;

	temp = MAX_VALUE;

	int mul = r[start] * r[end] * c[end];
	for (int i = start; i < end; i++)
		temp = min(temp, dp(start, i) + dp(i + 1, end) + mul);

	return temp;

}

void solve(int N)
{
	if (N == 1)
	{
		cout << '0';
		return;
	}
	int temp = MAX_VALUE;

	cout << dp(0, N - 1);
}
int main()
{
	cin.tie(NULL);
	memset(memory, -1, sizeof(memory));
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> r[i] >> c[i];
	
	solve(N);


}