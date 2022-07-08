#include <iostream>
#include <vector>

using namespace std;

class Que
{
public:
	int N;		//�� ��� ��
	int K;		//K  ��° ���� ����� �����Ѵ�.
	vector <int> data;		
	int index;		//�迭�� ���� �ε����� ����Ų��.

	Que(int N,int K):N(N),K(K)
	{
		for (int i = 0; i < N; i++)
			data.push_back(i + 1);		//push_back �Լ��� �̿��ؼ� ���� ũ�������� �迭 �Ҵ�

		index = K-1;		//���� �ε����� K-1 �� ����
	}
	int pop();

};

int main()
{
	int N;
	cin >> N;

	int K;
	cin >> K;

	Que q(N, K);

	cout << '<';
	while (N--)		//N�� �ݺ��ȴ�.
	{
		while (q.data[q.index] == 0)		//���� �� �迭�̸� index�� ���� �����ϴ� �迭�� �ε����� �ʱ�ȭ �Ѵ�.
		{
			q.index++;
			if (q.index >= q.N)
				q.index = 0;			//�ε����� ������ �Ѿ�� �ʱ� ��ġ�� �缳�� (��ȯ�� ����)
		}
		if (N > 0)
			cout << q.pop() << ", ";
		else
			cout << q.data[q.index] << '>';
	}

	return 0;
}

int Que::pop()
{
	int n = data[index];
	data[index] = 0;

	for (int i = 0; i < K; i++)
	{
		index++;
		if (index >= N)
			index = 0;
			while(data[index] == 0)
			{
				index++;
				if (index >= N)
					index = index % N;
			}
	}
	return n;		//���� �ε����� �迭���� ��ȯ �Ѵ�.
}