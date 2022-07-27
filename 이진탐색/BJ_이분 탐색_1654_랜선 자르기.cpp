#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//이진 탐색을 이용한 매개변순 탐색
int parameter_search(vector<int> &LAN, int N,int start,int end)
{
	int mid =(int)( ((long long)start + (long long)end) / 2);

	int n = 0;	//만들어진 LAN 총 개수
	for (int i = 0; i < LAN.size(); i++)
	{
		n += LAN[i] / mid;		//LAN선 길이를 mid 값으로 나눠 랜선 갯수를 더한다.
	}

	if (start >= end)
		if (n >= N)
			return mid;	//종료조건: start>=end 에서 랜선 개수 조건을 만족하면 mid 값을 반환하고
		else
			return mid - 1;	//랜선 개수 조건을 만족하지 않으면 mid-1 값을 반환한다.

	if (n >= N)
		return parameter_search(LAN, N, mid + 1, end);
	else if (n < N)
		return parameter_search(LAN, N, start, mid - 1);
	
}

int main()
{
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<int> LAN(K);
	for (int i = 0; i < K; i++)
		cin >> LAN[i];

	sort(LAN.begin(), LAN.end());

	int start = 1;	//LAN 길이의 최솟값
	int end = LAN.back();		//LAN 길이의 최댓값

	cout<<parameter_search(LAN, N, start, end);

}