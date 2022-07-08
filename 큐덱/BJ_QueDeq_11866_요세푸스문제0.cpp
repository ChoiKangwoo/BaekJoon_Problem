#include <iostream>
#include <vector>

using namespace std;

class Que
{
public:
	int N;		//총 사람 수
	int K;		//K  번째 마다 사람을 제거한다.
	vector <int> data;		
	int index;		//배열의 현재 인덱스를 가리킨다.

	Que(int N,int K):N(N),K(K)
	{
		for (int i = 0; i < N; i++)
			data.push_back(i + 1);		//push_back 함수를 이용해서 벡터 크기조정과 배열 할당

		index = K-1;		//현재 인덱스를 K-1 로 설정
	}
	int pop();

};

int main()
{
	int N;
	cin >> N;

	int K;
	cin >> K;

	Que q(N, K);

	cout << '<';
	while (N--)		//N번 반복된다.
	{
		while (q.data[q.index] == 0)		//만약 빈 배열이면 index를 값이 존재하는 배열의 인덱스로 초기화 한다.
		{
			q.index++;
			if (q.index >= q.N)
				q.index = 0;			//인덱스가 범위를 넘어가면 초기 위치로 재설정 (순환적 구조)
		}
		if (N > 0)
			cout << q.pop() << ", ";
		else
			cout << q.data[q.index] << '>';
	}

	return 0;
}

int Que::pop()
{
	int n = data[index];
	data[index] = 0;

	for (int i = 0; i < K; i++)
	{
		index++;
		if (index >= N)
			index = 0;
			while(data[index] == 0)
			{
				index++;
				if (index >= N)
					index = index % N;
			}
	}
	return n;		//현재 인덱스의 배열값을 반환 한다.
}