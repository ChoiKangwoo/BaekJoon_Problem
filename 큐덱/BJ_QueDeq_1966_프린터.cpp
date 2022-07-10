#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Que {
public:
	vector <int> data;		//������ �߿䵵�� ����Ǿ� �ִ� ����
	int size;		//������ ���� �� ��
	vector<int>prioty;		//������ �߿䵵�� ������������ ���ĵǾ� �ִ� ����
	int m;

	Que(int size, int m) :size(size), m(m)		//Que �� ������, size�� M�� �Է¹޾� �����Ű�� data �� prioty ���͸� �ʱ�ȭ ��Ų��.
	{
		for (int i = 0; i < size; i++)
		{
			int n;
			cin >> n;
			data.push_back(n);
			prioty.push_back(n);
		}
		sort(prioty.begin(), prioty.end());	//�߿䵵 �������� ����

	}
	
};
int main()
{
	int N;
	cin >> N;		//�׽�Ʈ ����

	while (N--)
	{
		int size, m;
		cin >> size >> m;
		Que q(size, m);

		int i = 0;		//���� �ε���
		int count = 0;		//������ �� Ƚ��
		while (1)
		{
			if (q.data[i] == q.prioty.back())		//�߿䵵�� ���� ���ٸ�
			{
				q.data[i] = 0;		//���� �ε����� �迭 ���Ҹ� 0���� �����(����Ʈ �۾��� �ߴٴ� �ǹ�)
				q.prioty.pop_back();		//prioty ������ ������ ���Ҹ� ������Ų��.(�������� ������ ����)
				count++;		//����Ʈ�� ������ count�� ������Ų��.
				if (i++ == m)		//���� �츮�� ������ �˾ƺ���;� �� ����Ʈ �������ٸ� �ݺ����� ������.
					break;
			}
			else      //q.data[i]<q.prioty.back()
			{
				q.data.push_back(q.data[i]);		//���� �ε����� ���Ҹ� ���� �ڿ� �߰���Ű�� 0���� �ʱ�ȭ ��Ų��.
				q.data[i] = 0;
				if (m == i++)		//�츮�� ������ �˾ƺ��� �;��� ����Ʈ ������� m �� �������� �ʱ� M��° ������ ������ �����.
					m += size - count;
			}
		}
		cout << count << '\n';		//M��° ������ ���°�� ��µǾ����� ����Ѵ�.
	}
}