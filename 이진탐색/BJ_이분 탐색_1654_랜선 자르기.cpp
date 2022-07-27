#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//���� Ž���� �̿��� �Ű����� Ž��
int parameter_search(vector<int> &LAN, int N,int start,int end)
{
	int mid =(int)( ((long long)start + (long long)end) / 2);

	int n = 0;	//������� LAN �� ����
	for (int i = 0; i < LAN.size(); i++)
	{
		n += LAN[i] / mid;		//LAN�� ���̸� mid ������ ���� ���� ������ ���Ѵ�.
	}

	if (start >= end)
		if (n >= N)
			return mid;	//��������: start>=end ���� ���� ���� ������ �����ϸ� mid ���� ��ȯ�ϰ�
		else
			return mid - 1;	//���� ���� ������ �������� ������ mid-1 ���� ��ȯ�Ѵ�.

	if (n >= N)
		return parameter_search(LAN, N, mid + 1, end);
	else if (n < N)
		return parameter_search(LAN, N, start, mid - 1);
	
}

int main()
{
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<int> LAN(K);
	for (int i = 0; i < K; i++)
		cin >> LAN[i];

	sort(LAN.begin(), LAN.end());

	int start = 1;	//LAN ������ �ּڰ�
	int end = LAN.back();		//LAN ������ �ִ�

	cout<<parameter_search(LAN, N, start, end);

}