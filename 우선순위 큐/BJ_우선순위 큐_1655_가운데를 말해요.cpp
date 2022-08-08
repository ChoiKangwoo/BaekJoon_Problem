#include <iostream>
#include<queue>
#include <vector>

using namespace std;

//�߰��� mid ���� ���� ������ �����ϴ� ť
priority_queue<int, vector<int> > lower;
//mid ���� ���� ������ �����ϴ� ť
priority_queue<int, vector<int>, greater<int>> upper;


int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;

	int x;
	int mid;		//�߰���
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (i == 0)
			mid = x;

		//���� �Է��� x�� mid ���� Ŭ��
		else if (mid < x)
		{
			//lower ����� �� ū ���� ����.

			//lower ť�� upper ť�� ���� ���� ������ �϶�
			if (lower.size() == upper.size())
				upper.push(x);		//mid ���� �ٲ��� ����ä�� upper �� �� ����

			//����� upper ť�� �� ũ�ٸ�
			else if (lower.size() < upper.size())
			{
				//lower ť ������ ��ĭ �� ���ܿ´�. (mid �� �ٲ��.)
				lower.push(mid);
				upper.push(x);
				mid = upper.top();
				upper.pop();
			}

		}

		//x�� mid ���� �۰ų� ���� ��
		else if (x <= mid)
		{
			//lower ����� �� ū ���� ����.

			//���� ���� ������ �϶�
			if (lower.size() == upper.size())
			{
				//upper ť ������ �� ĭ �� ���ܿ´�. (mid �� �ٲ��.)
				upper.push(mid);
				lower.push(x);
				mid = lower.top();
				lower.pop();
			}
			//upper ����� �� Ŭ��
			else if (lower.size() < upper.size())
				lower.push(x);	//mid ���� �ٲ��� ����ä�� x ���� push �Ѵ�.

		}

		cout << mid << '\n';

	}


}