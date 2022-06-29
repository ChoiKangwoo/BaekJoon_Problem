#include <iostream>
#include <vector>
using namespace std;


int main()
{
	cin.tie(NULL);					//시간을 줄이기 위한 io 의 분리
	cout.tie(NULL);

	int N;			//N 개의 도시
	cin >> N;

	vector<int> distance(N - 1);			//각 도시의 거리를 나타내는 int형 배열
	for (int i = 0; i < N - 1; i++)
		cin >> distance[i];

	vector<int> oil(N);					//각 도시에서 판매되는 기름 가격 int 형 배열
	for (int i = 0; i < N; i++)
		cin >> oil[i];

	int min = 0;		//첫 도시에서 무조건 기름을 충전해야 하므로 min값을 0으로 초기화
	int dst = 0;		//임시 거리값을 저장하는 변수 ; 최소 기름값으로 갈 수 있는 최대 거리를 저장한다.

	long long cost = 0;			//최종 비용을 저장하는 변수 long long형으로 선언했다.

	for (int i = 0; i < N - 1; i++)
	{
		if (oil[min] > oil[i])		//기름 값이 더 저렴할 때
		{

			cost += (long long)dst*(long long)oil[min];		//지금까지 누적된 거리에 현재 최소기름값을 곱해 더한다.
			min = i;				//최소값의 인덱스를 새로 초기화 해준다.
			dst = distance[min];		//누적 거리를 지금 도시에서 다음 도시까지의 거리로 초기화한다.(최소값으로 한 번 초기화 되면 무조건 한번은 이 비용으로 가게되기 때문)
		}

		else            //최소비용이 안바뀌면 
			dst += distance[i];		//누적거리에 다음 도시까지의 거리를 더해준다.



	}

	cost += (long long)dst*(long long)oil[min];		//N-1 번째의 도시까지 반복문을 수행했을 때 마지막 cost 계산이 안되므로 반복문을 나온 후 한 번 선언해주었다.

	cout << cost;			//정답 출력




}

