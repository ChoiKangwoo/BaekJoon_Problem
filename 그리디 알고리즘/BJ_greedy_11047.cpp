#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	int N;      //number of kind of coin
	long K;     // sum of coin's value

	cin >> N >> K;

	vector <int> arr(N);		

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	long value = 0;		//반복문에서 합쳐진 코인들의 합의 값
	int j = N-1;				//arr 배열의 마지막 인덱스 넘버
	int count = 0;			// 동전을 몇번 더했는지의 횟수 (최솟값)

	while (1)
	{
		if ((value + arr[j]) <= K)			// value + arr[i] 이 K 값과 같거나 작을 때
		{
			value += arr[j];					// value = value + arr[i] , count 값 1 증가
			count++;
		}
		else
			j--;										// 클 경우에는 인덱스 넘버를 1 낮추어서 다시 반복문을 수행한다.

		if (value == K)							// K와 value 값이 같을 때 반복문을 종료한다.
			break;
	}

	cout << count;							// count 값을 출력함

}