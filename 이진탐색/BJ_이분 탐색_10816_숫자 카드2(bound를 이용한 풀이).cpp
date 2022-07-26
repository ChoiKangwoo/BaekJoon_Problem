#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
upper_bound와 lower_bound를 이용한 풀이이다.
upper_bound는 vector에 찾고자 하는 숫자 num 이 여러개 있을 때 num 이 들어있는 가장 큰 index 위치+1 을 return 하고
lower_bound는 num 이 첫 번째로 나오는 index 위치를 return 한다.
따라서 upper_bound-lower_bound 는 num 의 갯수가 되는것이다.(정렬 되어있을 때 한정)
메모리와 시간적 측면 모두 배열을 이용하는 것 보다 좋은 방법인거 같다.
*/

//사용한 메모리: 5224KB	걸린시간: 308 ms
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
		card.push_back(temp);
	}
	sort(card.begin(), card.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		cout << upper_bound(card.begin(), card.end(), temp) - lower_bound(card.begin(), card.end(), temp) << ' ';
	}

	return 0;

}