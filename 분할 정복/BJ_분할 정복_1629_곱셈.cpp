#include <iostream>
#include <vector>

using namespace std;
int product(int A, int B, int C)
{
	if (B == 0)
		return 1;

	long long temp = product(A, B / 2, C);
	
	temp = temp * temp%C;		//�ŵ������� �� �� C �� ������ ����� ���� ���� ����

	if (B % 2 == 0)		//power ���ڰ� ¦���� ���
		return temp;
	else			//power ���ڰ� Ȧ���� ��� A�� �ѹ� �� ������ �� ������ ����� �ؾ��Ѵ�.
		return A * temp%C;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout<<product(A, B, C);

}
