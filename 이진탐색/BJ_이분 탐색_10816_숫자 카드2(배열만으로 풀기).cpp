#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int counting[20000001] = { 0 };
/*
�ش� ����+10000000���� �ε����� ��� �Է¹��� ������ �ش������ counting[index]�� ������Ű��
�̺�Ž������ �ش� ���ڰ� ������ �� counting ���� return �Ѵ�.
*/
int search_card(vector<int> &card,int m,int start,int end)
{
	int mid = (start + end) / 2;	//�迭�� �߰� �ε��� ����
	

	if (card[mid] == m)	//�߰� �ε����� �� �񱳸� ���ؼ� �̺�Ž���� �Ѵ�.
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

