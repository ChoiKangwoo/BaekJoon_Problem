#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;						//�׽�Ʈ �� �ʱ�ȭ
	cin >> T;

	while (T--)
	{
		string arr = "";		//�ӽ� ���ڿ� ����
		cin >> arr;

		int index = 0;		

		char PS[51] = {};		//���� �������� Ȱ���� ���ڿ�  PS ����

		for (int i = 0; i < arr.size(); i++)
		{
			PS[index++] = arr[i];		//�ӽù��ڿ��� �ϳ��� PS ���ڿ��� �����Ѵ�.

			//���ӵ� () �� Ȯ�εǸ� �� ���ڸ� NULL ������ �ʱ�ȭ �ϰ� index�� ���δ�.
			if (index > 0 && PS[index-1] == ')'&&PS[index - 2] == '(')
			{
				PS[--index] = NULL;
				PS[--index] = NULL;
			}

		}

		//VPS ��� index�� ���� 0�̴�( PS �� ����Ǿ��ִ� ���� �����Ƿ�)
		if (index == 0)
			cout << "YES"<<'\n';
		//index�� 0 �� �ƴ϶�� VPS �� �ƴϴ�.( ��ȣ ���ڿ��� �������)
		else
			cout << "NO"<<'\n';

	}

	return 0;
}