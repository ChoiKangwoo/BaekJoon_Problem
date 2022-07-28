#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int parameter_search(vector<int> x, int C, int start, int end)
{
	int gap = (start + end) / 2; //������ ������ �ּ� ���� gap

	int count = 0;
	int point = x[0];	//�Ÿ��� ������
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] - point >= gap)	//�Ÿ��� ���� gap ���� ũ�ų� ������ ���� ����
		{
			count++;	
			point = x[i];	//������ �缳�� ���� �� ��ġ�� �缳���Ѵ�.
		}
	}

		if (start >= end)	//����Լ� ��������
			if (count >= C)
				return gap;
			else
				return gap - 1;

		if (count >= C)	//���� �������� ���ų� ������ T �ƴϸ� F
			return parameter_search(x, C, gap + 1, end);
		else
			return parameter_search(x, C, start, gap - 1); 

	



}

int main()
{
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> x(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];

	sort(x.begin(), x.end());

	int start = 1;
	int end = x.back()-x.front();

	cout<<parameter_search(x, C-1, start, end);	//������ ��ġ���� C - 1�� �ؾ� count�� �񱳰���


}