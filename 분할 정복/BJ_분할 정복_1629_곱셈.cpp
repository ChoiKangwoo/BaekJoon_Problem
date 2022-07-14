#include <iostream>
#include <vector>

using namespace std;
int product(int A, int B, int C)
{
	if (B == 0)
		return 1;

	long long temp = product(A, B / 2, C);
	
	temp = temp * temp%C;		//거듭제곱을 한 후 C 로 나머지 계산한 것을 새로 저장

	if (B % 2 == 0)		//power 숫자가 짝수일 경우
		return temp;
	else			//power 숫자가 홀수일 경우 A를 한번 더 곱해준 후 나머지 계산을 해야한다.
		return A * temp%C;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout<<product(A, B, C);

}
