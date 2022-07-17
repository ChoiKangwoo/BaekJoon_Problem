#include <iostream>

const int MOD = 1000000007;

using namespace std;
/* 
모듈러 연산은 곱셈형태에선 사용 할 수 있지만 분수 형태에서는 사용하기 어렵다 따라서 분수를 곱셈형태로 
바꿔서 모듈러 연산을 사용할 수 있도록 페르마의 소정리를 이용해서 조합계산의 모듈러 연산을 수행한다.
페르마의 소정리를 이용한 곱셈역원 :modinv(K,MOD) =K^(MOD-2)
적용한 식 : ( N / K ) % MOD = ( N * modinv(K,MOD) ) % MOD = ( N * K ^( MOD-2 ) % MOD
*/

//modinv를 구하는 함수 a 인자에는 K 가 M에는 MOD-2 가 들어가게 된다.(거듭제곱 빠르게 구하는 함수)
long long modinv(int a, int M) 
{
	if (M == 1)
		return a; 
	if (M == 0)
		return 1;

	long long temp =modinv(a,M / 2);		//거듭제곱으로 줄여질 때마다 재귀함수로 호출한다.

	if (M % 2)		//나머지가 1일 경우에 거듭제곱 형태에 a 를 곱한 값으로 return 한다. a*a^2
		return (long long)((temp*temp) % MOD)*a%MOD;
	else		//나머지가 0일 경우에 거듭제곱 형태로 return 한다. a^2
		return (long long)(temp*temp) % MOD;
}

//팩토리얼 계산하는 함수 구현
long long factorial(int N)
{
	if (N == 0)		//재귀함수 탈출 조건
		return 1;
	
	long long temp = N * factorial(N - 1)%MOD;

	return temp;
}


int main()
{
	int N, K;
	cin >> N >> K;
	//조합 (N C K) 를 계산하기 위한 과정
	long long a = factorial(N);		//N!
	long long b = factorial(K);		//K!
	long long c = factorial(N - K);	//(N-K)!

	long long inv_b = modinv(b, MOD - 2);	//b의 곱셈 역원
	long long inv_c = modinv(c, MOD - 2);	//c의 곱셈 역원

	cout << (a * inv_b%MOD)*inv_c%MOD;
	

}