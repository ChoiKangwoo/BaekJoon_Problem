#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memory[500][500];
int prefix_sum[500];
int cost[500];
const int temp = 999999999;	//충분히 큰 값

int dp(int start, int end)
{
	if (start == end)	//재귀종료조건: 구간크기가 1일 경우는 해당 파일 비용과 같으므로 바로 return 한다.
		return cost[start];

	int& ret = memory[start][end];
	if (ret != -1)	return ret;		//memory를 불러와서 이미 값이 저장되어 있으면 별도의 계산필요없이 바로 return 한다.

	ret = temp;	//최소값 비교를 위한 임시값 초기화

	int sum;
	if (start != 0)
		sum = prefix_sum[end] - prefix_sum[start - 1];	// start~end 의 구간합은 0~end 구간합 - 0~(start-1) 구간합이다.
	else
		sum = prefix_sum[end];	//start가 0 일경우 sum은 prefix_sum[end] 와 동일하다.

	for (int i = start; i < end; i++)
		ret = min(ret, dp(start, i) + dp(i + 1, end) + sum);	//파일을 합치기 전의 비용과 sum의 합이 파일을 합치는데 필요한 총 비용이다.

	return ret;

}

void solve(int K)
{
	int ret = temp;

	//구간합이 더 작은 경우를 찾을 때마다 ret 값을 갱신하면서 결과적으로는 최소값을 갖게된다.
	for (int i = 0; i < K - 1; i++)
		//최종 파일비용들의 합을 계산한다. 이 단계에서는 sum 더해줄 필요 없음!! 이미 return 받은 dp 값 안에 sum 이 저장되어 있음
		//sum1+sum2=sum
		ret = min(ret, dp(0, i) + dp(i + 1, K - 1));

	cout << ret << '\n';
}


int main()
{
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		memset(memory, -1, sizeof(memory)); //memory 비워주는 작업

		int K;
		cin >> K;

		for (int i = 0; i < K; i++)
			cin >> cost[i];

		for (int j = 0; j < K; j++)
		{
			if (j != 0)
				prefix_sum[j] = prefix_sum[j - 1] + cost[j];	//점화식: 0~j 번째 파일 까지의 비용 합= 0~j-1 까지 합+j 번째 파일 비용

			else
				prefix_sum[j] = cost[0];	//첫 원소는 이전원소가 존재하지 않으므로 예외를 두어 계산
		}

		solve(K);

	}

	return 0;
}