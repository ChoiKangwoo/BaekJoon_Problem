#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int counting[20000001] = { 0 };
/*
해당 숫자+10000000값을 인덱스로 삼아 입력받을 때마다 해당숫자의 counting[index]를 증가시키고
이분탐색으로 해당 숫자가 나왔을 때 counting 값을 return 한다.
*/
int search_card(vector<int> &card,int m,int start,int end)
{
	int mid = (start + end) / 2;	//배열의 중간 인덱스 설정
	

	if (card[mid] == m)	//중간 인덱스와 의 비교를 통해서 이분탐색을 한다.
	{
		return counting[m+10000000];
	}
	else if (start >= end)
		return 0;

	else if (card[mid] < m)
		return search_card(card, m, mid + 1, end);
	else if (card[mid] > m)
		return search_card(card, m, start, mid - 1);
	else
		return 0;

}
	

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

