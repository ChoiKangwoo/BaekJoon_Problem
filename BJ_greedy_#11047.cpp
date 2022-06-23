#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	int N;      //number of kind of coin
	long K;     // sum of coin's value

	cin >> N >> K;

	vector <int> arr(N);		

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	long value = 0;		//�ݺ������� ������ ���ε��� ���� ��
	int j = N-1;				//arr �迭�� ������ �ε��� �ѹ�
	int count = 0;			// ������ ��� ���ߴ����� Ƚ�� (�ּڰ�)

	while (1)
	{
		if ((value + arr[j]) <= K)			// value + arr[i] �� K ���� ���ų� ���� ��
		{
			value += arr[j];					// value = value + arr[i] , count �� 1 ����
			count++;
		}
		else
			j--;										// Ŭ ��쿡�� �ε��� �ѹ��� 1 ���߾ �ٽ� �ݺ����� �����Ѵ�.

		if (value == K)							// K�� value ���� ���� �� �ݺ����� �����Ѵ�.
			break;
	}

	cout << count;							// count ���� �����

}