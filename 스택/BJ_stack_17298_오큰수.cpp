#include <iostream>
#include <vector>

using namespace std;

void NGE(vector<int> &A)
{
	vector<int> X;		//X배열에 오큰수를 스택 개념으로 집어넣는다.
	vector<int> NGE;		//NGE 수들을 저장하는 배열
	int N = A.size();

	//A[i] 과 X.back 을 비교하여 오큰수를 판별한다.
	for (int i =N-1; i >=0; i--)
	{
		while (1)
		{
			//X가 비어있을 경우=A[i]의 오큰수가 없다.
			if (X.empty())
			{
				NGE.push_back(-1);	//이 경우 -1 을 저장하고,  X배열에 A[i]를 pushback 한다.
				X.push_back(A[i]);
				break;
			}
			//X.back > A[i]일 경우 = 오큰수가 존재한다.
			else if (A[i] < X.back())
				{
					NGE.push_back(X.back());	//X.back이 A[i]의 오른쪽 중에서 가장 가까운 큰 수 이다.
					X.push_back(A[i]);	//X의 맨 위에 A[i]를 pushback
					break;
				}
			//X.back <A[i] 일경우 = X.back이 오큰수가 아니다.
			else if (A[i] >= X.back())
				//X의 맨위에있는 원소를 pop 시키고 다음 원소와 비교해 오큰수를 판별하게 한다.
				X.pop_back();
			
		}
	}
	//맨위에 있는 원소부터 출력하여 순서를 맞춘다.
	for (int i = NGE.size() - 1; i >= 0; i--)
		cout << NGE[i] << ' ';

}
int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	NGE(A);

}