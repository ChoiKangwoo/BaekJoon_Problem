#include <iostream>
#include <vector>
using namespace std;

int find_min_oil(vector<int> &oil, int end);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;			//N ���� ����
	cin >> N;

	vector<int> distance (N-1);			//�� ������ �Ÿ��� ��Ÿ���� int�� �迭
	for (int i = 0; i < N - 1; i++)
		cin >> distance[i];

	vector<int> oil(N);					//�� ���ÿ��� �ǸŵǴ� �⸧ ���� int �� �迭
	for (int i = 0; i < N; i++)
		cin >> oil[i];

	int min=N-1;		//oil ���� �ּ��� ���ø� ��Ÿ���� index ��ȣ�̴�.
	int end;			//�������� ������ ���ø� ��Ÿ���� index ��ȣ�̴�.

	
	long long cost = 0;

	while (1)
	{
		int dst = 0;
		end = min - 1;
		min = find_min_oil(oil, end);

		for (int i = min; i <= end; i++)
			dst += distance[i];

		cost += (long long)dst*(long long)oil[min];

		

		if (min == 0)
			break;
	}
	
	cout << cost;




}

//�������� �⸧���� �ּ��� index �� ã�� index�� return �Ѵ�.
int find_min_oil(vector<int> &oil, int end)
{
	int min = 0;
	for (int i = 0; i <=end; i++)
		if (oil[min] > oil[i])
			min = i;
	
	return min;
}