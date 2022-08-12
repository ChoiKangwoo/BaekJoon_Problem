#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_VALUE = 2147483646;
int r[500];		// 행렬에서 행의 크기 저장
int c[500];		//행렬에서 열의 크기 저장
int memory[500][500];	//start~end 행까지의 필요한 곱셈 횟수를 저장(최솟값)


int dp(int start, int end)
{
	if (start == end)		//구간의 크기가 1일때 더 쪼갤 수 있는 행렬이 없으므로 0 반환
		return 0;

	if (memory[start][end] != MAX_VALUE)	return  memory[start][end];		//memory에 저장되어 있는 값이 있으면 바로 반환한다.


	for (int i = start; i < end; i++)
		//행렬 곱셈의 횟수를 계산하는 점화식이다.
		//점화식을 토대로 memory의 최솟값을 찾는다.
		memory[start][end] = min(memory[start][end], dp(start, i) + dp(i + 1, end) + r[start] * c[i] * c[end]);

	//구한 memory 값을 반환한다.
	return memory[start][end];

}

void solve(int N)
{
	//행렬의 크기가 1이 주어졌을 때는 0을 반환한다.
	if (N == 1)
	{
		cout << '0';
		return;
	}

	//답 출력
	cout << dp(0, N - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//memory 영역을 모두 MAX_VALUE로 초기화 시킨다.
	fill_n(&memory[0][0], 500 * 500, MAX_VALUE);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> r[i] >> c[i];

	solve(N);

}