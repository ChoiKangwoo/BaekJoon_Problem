#include <iostream>
#include <vector>
using namespace std;

int find_min_oil(vector<int> &oil, int end);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;			//N 개의 도시
	cin >> N;

	vector<int> distance (N-1);			//각 도시의 거리를 나타내는 int형 배열
	for (int i = 0; i < N - 1; i++)
		cin >> distance[i];

	vector<int> oil(N);					//각 도시에서 판매되는 기름 가격 int 형 배열
	for (int i = 0; i < N; i++)
		cin >> oil[i];

	int min=N-1;		//oil 값이 최소인 도시를 나타내는 index 번호이다.
	int end;			//범위내의 마지막 도시를 나타내는 index 번호이다.

	
	long long cost = 0;

	while (1)
	{
		int dst = 0;
		end = min - 1;
		min = find_min_oil(oil, end);

		for (int i = min; i <= end; i++)
			dst += distance[i];

		cost += (long long)dst*(long long)oil[min];

		

		if (min == 0)
			break;
	}
	
	cout << cost;




}

//범위내의 기름값이 최소인 index 를 찾아 index를 return 한다.
int find_min_oil(vector<int> &oil, int end)
{
	int min = 0;
	for (int i = 0; i <=end; i++)
		if (oil[min] > oil[i])
			min = i;
	
	return min;
}