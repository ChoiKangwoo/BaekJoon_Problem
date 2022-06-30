#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;						//테스트 수 초기화
	cin >> T;

	while (T--)
	{
		string arr = "";		//임시 문자열 선언
		cin >> arr;

		int index = 0;		

		char PS[51] = {};		//스택 개념으로 활용할 문자열  PS 선언

		for (int i = 0; i < arr.size(); i++)
		{
			PS[index++] = arr[i];		//임시문자열을 하나씩 PS 문자열에 복사한다.

			//연속된 () 가 확인되면 두 문자를 NULL 값으로 초기화 하고 index를 줄인다.
			if (index > 0 && PS[index-1] == ')'&&PS[index - 2] == '(')
			{
				PS[--index] = NULL;
				PS[--index] = NULL;
			}

		}

		//VPS 라면 index의 값은 0이다( PS 에 저장되어있는 값이 없으므로)
		if (index == 0)
			cout << "YES"<<'\n';
		//index가 0 이 아니라면 VPS 가 아니다.( 괄호 문자열이 살아있음)
		else
			cout << "NO"<<'\n';

	}

	return 0;
}