#include <iostream>
#include <vector>

using namespace std;

class Que {
public:
	vector <int> data;		//ī�������� ���� �迭�� vector Ŭ������ ����
	int first;		//ī���� ���� ����
	int last;		//ī���� ���� �Ʒ���
	int N;		//ī���� �� ��
	Que(int N):N(N)		//Ŭ���� ������
	{
		for (int i = 0; i < N; i++)
			data.push_back( i+1);		//������������ ī�� ���� push_back �Լ��� ���� ũ�⸦ �ø��鼭 �Ҵ�

		first = 0;		//0��° �ε����� ���� ����
		last = N-1;	//N-1��° �ε����� ���� �Ʒ���
	}

	void discard();		//Ȧ�� ��°�� ����Ǵ� ���� ���� ������ �Լ�
	void bottom();			//¦�� ������ ����Ǵ� ���� ������ �Ʒ������� �ű�� �Լ�
};


int main()
{
	int N;
	cin >> N;		//N���� ī��

	Que q(N);		

	while (1)
	{
		if (N == 1)		//ī�� ����� ������ ���� �������� �ʰ� �ٷ� �����Ѵ�.
			break;

		q.discard();	

		if (q.first == q.last)		//ī�带 ������ �� �� ī�尡 �� �� �ۿ� ���� ���� ��� �ݺ����� �����Ѵ�.
			break;

		q.bottom();


	}

	cout << q.data[q.first];
	
	return 0;

}

void Que::discard()
{
	data[first++] = 0;		//0���� �ʱ�ȭ �ϴ� �۾�=ī�� ������
	if (first == N)		//first ������ �ε��� ������ �Դٸ� 0���� �ʱ�ȭ(��ȯ���� ť��� �����ϸ� �ȴ�.)
		first = 0;
}

void Que::bottom()
{
	int n = data[first];		//������ ī�带 �Ʒ������� �ű�� �۾�
	data[first++] = 0;
	if (last == N - 1)			//last�� �ε����� ���̶�� -1���� �ʱ�ȭ (��ȯ���� ť���� ������ ������ 0�̴�.)
		last = -1;
	data[++last] =n;		

	if (first == N)			
		first = 0;

}