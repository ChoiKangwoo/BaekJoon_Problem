#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
upper_bound�� lower_bound�� �̿��� Ǯ���̴�.
upper_bound�� vector�� ã���� �ϴ� ���� num �� ������ ���� �� num �� ����ִ� ���� ū index ��ġ+1 �� return �ϰ�
lower_bound�� num �� ù ��°�� ������ index ��ġ�� return �Ѵ�.
���� upper_bound-lower_bound �� num �� ������ �Ǵ°��̴�.(���� �Ǿ����� �� ����)
�޸𸮿� �ð��� ���� ��� �迭�� �̿��ϴ� �� ���� ���� ����ΰ� ����.
*/

//����� �޸�: 5224KB	�ɸ��ð�: 308 ms
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