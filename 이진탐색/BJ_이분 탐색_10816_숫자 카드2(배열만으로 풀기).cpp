#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int counting[20000001] = { 0 };
/*
�ش� ����+10000000���� �ε����� ��� �Է¹��� ������ �ش������ counting[index]�� ������Ű��
ã���� �ϴ� ���� �Է¹����� ���ÿ� counting[temp+10000000]�� ��½�Ų��.
*/

// ����� �޸�: 83344KB		�ɸ��ð�: 316ms
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

