#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);

	while(1)	//�Է¹��� ���簢���� ������ 0�̸� ����ȴ�.
	{
		int n;		//���簢���� ����
		cin >> n;
		if (n == 0)
			break;

		vector <int> h;		//������׷��� �Է¹޴� ����
		vector<int> stack;	//stack���� ���簢���� ���̰� �ƴ� index(���° ���簢������) �� ����Ǿ� �־� h[index] ���·� ���̸� ȣ���Ѵ�.
		vector<long long> ans;	//���� ���̵��� ����Ǿ��ִ� ���� ans
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;		//���簢���� ���̸� �Է¹޴´�.
			h.push_back(a);

			if(i>0)
				while (1)	//stack�� ����ְų� �Է¹��� ���簢���� ���̰� stack �� top ���̺��� ũ�ٸ� �ݺ����� �����Ѵ�.
				{
					if (stack.empty())
						break;
					if (a >= h[stack.back()])
						break;

					long long s;	//���̸� �޴� ����
					int index = stack.back();	//stack�� top value�� index�� �޴´�. 
					stack.pop_back();	//�����Ѵ�.

					if (stack.size() == 0)	//���������� pop �Ǵ� index��  0~i-1 �������� �������� ���簢���̹Ƿ� �ش籸�����̿� ���簢�� ���̸� �����ش�.
						s =(long long) (i)*(long long)h[index];
					else		//�� �̿��� ���� stack�� top���κ��� �� ��°�� ����Ǿ��ִ� ���簢���� i ��° ��ġ�� �ִ� ���簢�� ���̱��̿� ���簢�� ���̸� �����ش�.
					s = (long long)(i- stack.back()-1)*(long long)h[index];

					ans.push_back(s);	//���� ���̸� �����Ѵ�.
					
				}	

			stack.push_back(i);	//stack data�� push ���ش�.

		}
		while (!stack.empty())		//�ݺ����� ��ġ�� stack �� �����ִ� data��� ���� ����������� ���̸� �����ش�
		{
			long long s;
			int index = stack.back();
			stack.pop_back();
			if (stack.size() == 0)
				s = (long long)(n)*(long long)h[index];
			else
				s =(long long)(n -stack.back()-1)*(long long)h[index];

			ans.push_back(s);
		}

		long long max = *max_element(ans.begin(), ans.end());	//���� ���̵� �߿��� ���� ū ���� ����Ѵ�.
		cout << max << '\n';

	}
}