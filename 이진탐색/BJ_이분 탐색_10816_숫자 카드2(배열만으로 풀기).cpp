#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int counting[20000001] = { 0 };
/*
해당 숫자+10000000값을 인덱스로 삼아 입력받을 때마다 해당숫자의 counting[index]를 증가시키고
찾고자 하는 값을 입력받음과 동시에 counting[temp+10000000]을 출력시킨다.
*/

// 사용한 메모리: 83344KB		걸린시간: 316ms
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int temp;
	vector<int> card;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		counting[temp+10000000]++;
		card.push_back(temp);
	}
	sort(card.begin(), card.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		cout << counting[temp+10000000]<<' ';
	}

	return 0;

}

