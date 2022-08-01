#include <iostream>
#include <vector>

using namespace std;

void NGE(vector<int> &A)
{
	vector<int> X;		//X�迭�� ��ū���� ���� �������� ����ִ´�.
	vector<int> NGE;		//NGE ������ �����ϴ� �迭
	int N = A.size();

	//A[i] �� X.back �� ���Ͽ� ��ū���� �Ǻ��Ѵ�.
	for (int i =N-1; i >=0; i--)
	{
		while (1)
		{
			//X�� ������� ���=A[i]�� ��ū���� ����.
			if (X.empty())
			{
				NGE.push_back(-1);	//�� ��� -1 �� �����ϰ�,  X�迭�� A[i]�� pushback �Ѵ�.
				X.push_back(A[i]);
				break;
			}
			//X.back > A[i]�� ��� = ��ū���� �����Ѵ�.
			else if (A[i] < X.back())
				{
					NGE.push_back(X.back());	//X.back�� A[i]�� ������ �߿��� ���� ����� ū �� �̴�.
					X.push_back(A[i]);	//X�� �� ���� A[i]�� pushback
					break;
				}
			//X.back <A[i] �ϰ�� = X.back�� ��ū���� �ƴϴ�.
			else if (A[i] >= X.back())
				//X�� �������ִ� ���Ҹ� pop ��Ű�� ���� ���ҿ� ���� ��ū���� �Ǻ��ϰ� �Ѵ�.
				X.pop_back();
			
		}
	}
	//������ �ִ� ���Һ��� ����Ͽ� ������ �����.
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