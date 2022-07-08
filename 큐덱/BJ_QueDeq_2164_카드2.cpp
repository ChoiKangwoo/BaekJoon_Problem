#include <iostream>
#include <vector>

using namespace std;

class Que {
public:
	vector <int> data;		//카드저장을 위한 배열을 vector 클래스로 선언
	int first;		//카드의 제일 윗장
	int last;		//카드의 제일 아랫장
	int N;		//카드의 장 수
	Que(int N):N(N)		//클래스 생성자
	{
		for (int i = 0; i < N; i++)
			data.push_back( i+1);		//오름차순으로 카드 저장 push_back 함수로 벡터 크기를 늘리면서 할당

		first = 0;		//0번째 인덱스가 제일 윗장
		last = N-1;	//N-1번째 인덱스가 제일 아랫장
	}

	void discard();		//홀수 번째에 시행되는 제일 윗장 버리기 함수
	void bottom();			//짝수 번쨰에 시행되는 제일 윗장을 아랫장으로 옮기는 함수
};


int main()
{
	int N;
	cin >> N;		//N장의 카드

	Que q(N);		

	while (1)
	{
		if (N == 1)		//카드 장수가 한장일 때는 실행하지 않고 바로 종료한다.
			break;

		q.discard();	

		if (q.first == q.last)		//카드를 버리고 난 후 카드가 한 장 밖에 남지 않은 경우 반복문을 종료한다.
			break;

		q.bottom();


	}

	cout << q.data[q.first];
	
	return 0;

}

void Que::discard()
{
	data[first++] = 0;		//0으로 초기화 하는 작업=카드 버리기
	if (first == N)		//first 변수가 인덱스 끝까지 왔다면 0으로 초기화(순환적인 큐라고 생각하면 된다.)
		first = 0;
}

void Que::bottom()
{
	int n = data[first];		//윗장의 카드를 아랫장으로 옮기는 작업
	data[first++] = 0;
	if (last == N - 1)			//last가 인덱스의 끝이라면 -1으로 초기화 (순환적인 큐에서 마지막 다음은 0이다.)
		last = -1;
	data[++last] =n;		

	if (first == N)			
		first = 0;

}