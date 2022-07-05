#include <iostream>
#include <vector>

using namespace std;

int index = 0;

int inspect(vector <int> &arr, int N);
void push(int &stack, int n);
void pop(int &stack);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];						//���� ����

	vector <int> stack(N, 0);		//���ñ����� ������ �迭 stack ��� ���Ҹ� 0���� �ʱ�ȭ

	//���� ���ɼ� �Ǵܱ���, �Ұ����ΰ�� NO �� ����ϰ� �����Ѵ�.
	if (inspect(arr, N) == 1)
	{
		cout << "NO";
		return 0;
	}

	//stack ������ Ȱ���� 'push'�� 'pop' ��´ܰ�

	int n=0;			//����� ������ �ε��� �ѹ�
	int s = 1;			//stack ������ Ȱ���ϴ� ��
	int top = 0;		// stack �迭�� ������ ��Ҹ� ����Ű�� �ε��� �ѹ�

	while (n<N)
	{
		if (arr[n] == stack[top])				//�ش� ������ ���ڿ� stack �迭�� ����� ���ڰ� ���� ��� 'pop' �� �Ѵ�.
		{
			pop(stack[--index]);
			n++;											//'pop'�� �� �� ���� ������ ���ڷ� �Ѿ��.
		}

		else if (arr[n] > stack[top])			//�ش� ������ ���ں��� stack[top] �� ����Ǿ� �ִ� ���ڰ� ������� stack �迭�� s �� 'push' ���ش�.
			push(stack[index++], s++);		//push �� �� s++ ���ش�.(������������ push�� ���ֱ� ����)
		
		if(index>0)			//index=0 �� ��쿡�� top=-1 �� �ǹǷ� �迭�� ������ �Ѿ�� �ȴ�.
		top = index - 1;	

	}
		


}

int inspect(vector <int> &arr,int N)
{
	vector <int> c(N+1, 1);		//�˻��ϱ� ���� �迭 c �̴�. �� c[i] ���� i�� ������ ���ڸ� ��Ÿ����.
												//c[i]�� 0 �Ǵ� 1 ����Ǹ� 1 �ΰ��� ���� �� ���ڰ� pop �� �ȵ� ���°�, 0�̸�  pop�� �� ���´�.

	int max = arr[0];					//0~i ���� ������ arr[] �� max ���� �����ϴ� �����̴�. max �� ���ķ� arr[i] ������ ������������ �Ǿ��־�� �Ѵ�.
												//max ���� �ǹ��ϴ� �ٴ� �� max �� ���� ������������ push �� �Ǿ��ٴ� ���̱⵵ �ϴ�.

	for (int i = 0; i < N; i++)
	{
		c[arr[i]] = 0;						//���� ������ ���ڰ� pop �Ǿ����Ƿ� 0���� �ʱ�ȭ ���ش�.

		if (max < arr[i])				//max ���� �ʱ�ȭ �����ش�. max ���� �ʱ�ȭ �����ִ� �ǹ̴� max ������ push�� �ߴٴ� ���̴�.
			max = arr[i];

		else if (max > arr[i])		//������������ �Ǿ��־�� �Ѵ�.
		{
			if (c[arr[i] + 1] == 1)		//���� �������� 1 ��ŭ ���� ���ڰ� ���� pop�� �ȵǾ��ٸ� ���� ������ pop �� �� �� ����.
				return 1;						//��ȯ���� 1�̸� ����� �Ұ���
		}
		/*���� ��� 4 2 5 6 8 7 3 1 ���� 2�� 4���� �����Ƿ� ���������� ���������� ��Ų�� ������ 3�� ���� pop �� �ȵǾ����Ƿ� 2�� ���� pop �� ���� ����.*/
	
	}

	return 0;									//��ȯ���� 0�̸� ����� ����
}

void push(int &stack, int n)
{
	stack = n;
	cout << '+' << '\n';
}

void pop(int &stack)
{
	stack = 0;
	cout << '-' << '\n';
}