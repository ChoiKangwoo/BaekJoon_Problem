#include <iostream>
#include <vector>
using namespace std;


int main()
{
	cin.tie(NULL);					//�ð��� ���̱� ���� io �� �и�
	cout.tie(NULL);

	int N;			//N ���� ����
	cin >> N;

	vector<int> distance(N - 1);			//�� ������ �Ÿ��� ��Ÿ���� int�� �迭
	for (int i = 0; i < N - 1; i++)
		cin >> distance[i];

	vector<int> oil(N);					//�� ���ÿ��� �ǸŵǴ� �⸧ ���� int �� �迭
	for (int i = 0; i < N; i++)
		cin >> oil[i];

	int min = 0;		//ù ���ÿ��� ������ �⸧�� �����ؾ� �ϹǷ� min���� 0���� �ʱ�ȭ
	int dst = 0;		//�ӽ� �Ÿ����� �����ϴ� ���� ; �ּ� �⸧������ �� �� �ִ� �ִ� �Ÿ��� �����Ѵ�.

	long long cost = 0;			//���� ����� �����ϴ� ���� long long������ �����ߴ�.

	for (int i = 0; i < N - 1; i++)
	{
		if (oil[min] > oil[i])		//�⸧ ���� �� ������ ��
		{

			cost += (long long)dst*(long long)oil[min];		//���ݱ��� ������ �Ÿ��� ���� �ּұ⸧���� ���� ���Ѵ�.
			min = i;				//�ּҰ��� �ε����� ���� �ʱ�ȭ ���ش�.
			dst = distance[min];		//���� �Ÿ��� ���� ���ÿ��� ���� ���ñ����� �Ÿ��� �ʱ�ȭ�Ѵ�.(�ּҰ����� �� �� �ʱ�ȭ �Ǹ� ������ �ѹ��� �� ������� ���ԵǱ� ����)
		}

		else            //�ּҺ���� �ȹٲ�� 
			dst += distance[i];		//�����Ÿ��� ���� ���ñ����� �Ÿ��� �����ش�.



	}

	cost += (long long)dst*(long long)oil[min];		//N-1 ��°�� ���ñ��� �ݺ����� �������� �� ������ cost ����� �ȵǹǷ� �ݺ����� ���� �� �� �� �������־���.

	cout << cost;			//���� ���




}

