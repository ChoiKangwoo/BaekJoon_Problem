#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int parameter_search(vector<int> x, int C, int start, int end)
{
	int gap = (start + end) / 2; //공유기 사이의 최소 간격 gap

	int count = 0;
	int point = x[0];	//거리의 기준점
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] - point >= gap)	//거리의 차가 gap 보다 크거나 같으면 조건 성립
		{
			count++;	
			point = x[i];	//기준점 재설정 현재 집 위치로 재설정한다.
		}
	}

		if (start >= end)	//재귀함수 종료조건
			if (count >= C)
				return gap;
			else
				return gap - 1;

		if (count >= C)	//기준 갯수보다 많거나 같으면 T 아니면 F
			return parameter_search(x, C, gap + 1, end);
		else
			return parameter_search(x, C, start, gap - 1); 

	



}

int main()
{
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> x(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];

	sort(x.begin(), x.end());

	int start = 1;
	int end = x.back()-x.front();

	cout<<parameter_search(x, C-1, start, end);	//공유기 설치갯수 C - 1을 해야 count와 비교가능


}