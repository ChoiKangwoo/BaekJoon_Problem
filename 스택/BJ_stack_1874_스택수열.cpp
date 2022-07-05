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
		cin >> arr[i];						//수열 저장

	vector <int> stack(N, 0);		//스택구조로 저장할 배열 stack 모든 원소를 0으로 초기화

	//수열 가능성 판단구간, 불가능인경우 NO 를 출력하고 종료한다.
	if (inspect(arr, N) == 1)
	{
		cout << "NO";
		return 0;
	}

	//stack 구조를 활용한 'push'와 'pop' 출력단계

	int n=0;			//저장된 수열의 인덱스 넘버
	int s = 1;			//stack 구조를 활용하는 수
	int top = 0;		// stack 배열의 마지막 요소를 가리키는 인덱스 넘버

	while (n<N)
	{
		if (arr[n] == stack[top])				//해당 수열의 숫자와 stack 배열에 저장된 숫자가 같을 경우 'pop' 을 한다.
		{
			pop(stack[--index]);
			n++;											//'pop'을 한 뒤 다음 수열의 숫자로 넘어간다.
		}

		else if (arr[n] > stack[top])			//해당 수열의 숫자보다 stack[top] 에 저장되어 있는 숫자가 작을경우 stack 배열에 s 를 'push' 해준다.
			push(stack[index++], s++);		//push 한 후 s++ 해준다.(오름차순으로 push를 해주기 때문)
		
		if(index>0)			//index=0 인 경우에는 top=-1 이 되므로 배열의 범위를 넘어가게 된다.
		top = index - 1;	

	}
		


}

int inspect(vector <int> &arr,int N)
{
	vector <int> c(N+1, 1);		//검사하기 위한 배열 c 이다. 각 c[i] 에서 i는 수열의 숫자를 나타낸다.
												//c[i]는 0 또는 1 저장되며 1 인경우는 아직 그 숫자가 pop 이 안된 상태고, 0이면  pop이 된 상태다.

	int max = arr[0];					//0~i 범위 까지의 arr[] 의 max 값을 저장하는 변수이다. max 값 이후로 arr[i] 까지는 내림차순으로 되어있어야 한다.
												//max 값이 의미하는 바는 그 max 값 까지 오름차순으로 push 가 되었다는 뜻이기도 하다.

	for (int i = 0; i < N; i++)
	{
		c[arr[i]] = 0;						//현재 수열의 숫자가 pop 되었으므로 0으로 초기화 해준다.

		if (max < arr[i])				//max 값을 초기화 시켜준다. max 값을 초기화 시켜주는 의미는 max 값까지 push를 했다는 뜻이다.
			max = arr[i];

		else if (max > arr[i])		//내림차순으로 되어있어야 한다.
		{
			if (c[arr[i] + 1] == 1)		//현재 수열보다 1 만큼 높은 숫자가 아직 pop이 안되었다면 현재 수열은 pop 이 될 수 없다.
				return 1;						//반환값이 1이면 만들기 불가능
		}
		/*예를 들어 4 2 5 6 8 7 3 1 에서 2는 4보다 작으므로 구간내에서 내림차순을 지킨게 맞지만 3이 아직 pop 이 안되었으므로 2가 먼저 pop 될 수는 없다.*/
	
	}

	return 0;									//반환값이 0이면 만들기 가능
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