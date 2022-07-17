#include <iostream>

const int MOD = 1000000007;

using namespace std;
/* 
��ⷯ ������ �������¿��� ��� �� �� ������ �м� ���¿����� ����ϱ� ��ƴ� ���� �м��� �������·� 
�ٲ㼭 ��ⷯ ������ ����� �� �ֵ��� �丣���� �������� �̿��ؼ� ���հ���� ��ⷯ ������ �����Ѵ�.
�丣���� �������� �̿��� �������� :modinv(K,MOD) =K^(MOD-2)
������ �� : ( N / K ) % MOD = ( N * modinv(K,MOD) ) % MOD = ( N * K ^( MOD-2 ) % MOD
*/

//modinv�� ���ϴ� �Լ� a ���ڿ��� K �� M���� MOD-2 �� ���� �ȴ�.(�ŵ����� ������ ���ϴ� �Լ�)
long long modinv(int a, int M) 
{
	if (M == 1)
		return a; 
	if (M == 0)
		return 1;

	long long temp =modinv(a,M / 2);		//�ŵ��������� �ٿ��� ������ ����Լ��� ȣ���Ѵ�.

	if (M % 2)		//�������� 1�� ��쿡 �ŵ����� ���¿� a �� ���� ������ return �Ѵ�. a*a^2
		return (long long)((temp*temp) % MOD)*a%MOD;
	else		//�������� 0�� ��쿡 �ŵ����� ���·� return �Ѵ�. a^2
		return (long long)(temp*temp) % MOD;
}

//���丮�� ����ϴ� �Լ� ����
long long factorial(int N)
{
	if (N == 0)		//����Լ� Ż�� ����
		return 1;
	
	long long temp = N * factorial(N - 1)%MOD;

	return temp;
}


int main()
{
	int N, K;
	cin >> N >> K;
	//���� (N C K) �� ����ϱ� ���� ����
	long long a = factorial(N);		//N!
	long long b = factorial(K);		//K!
	long long c = factorial(N - K);	//(N-K)!

	long long inv_b = modinv(b, MOD - 2);	//b�� ���� ����
	long long inv_c = modinv(c, MOD - 2);	//c�� ���� ����

	cout << (a * inv_b%MOD)*inv_c%MOD;
	

}