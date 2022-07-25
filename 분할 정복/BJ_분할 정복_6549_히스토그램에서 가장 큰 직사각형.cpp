#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);

	while(1)	//입력받은 직사각형의 갯수가 0이면 종료된다.
	{
		int n;		//직사각형의 갯수
		cin >> n;
		if (n == 0)
			break;

		vector <int> h;		//히스토그램을 입력받는 벡터
		vector<int> stack;	//stack에는 직사각형의 높이가 아닌 index(몇번째 직사각형인지) 가 저장되어 있어 h[index] 형태로 높이를 호출한다.
		vector<long long> ans;	//구한 넓이들이 저장되어있는 벡터 ans
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;		//직사각형의 높이를 입력받는다.
			h.push_back(a);

			if(i>0)
				while (1)	//stack이 비어있거나 입력받은 직사각형의 높이가 stack 의 top 높이보다 크다면 반복문을 종료한다.
				{
					if (stack.empty())
						break;
					if (a >= h[stack.back()])
						break;

					long long s;	//넓이를 받는 변수
					int index = stack.back();	//stack의 top value를 index로 받는다. 
					stack.pop_back();	//제거한다.

					if (stack.size() == 0)	//마지막으로 pop 되는 index는  0~i-1 구간에서 제일작은 직사각형이므로 해당구간길이에 직사각형 높이를 곱해준다.
						s =(long long) (i)*(long long)h[index];
					else		//그 이외의 경우는 stack의 top으로부터 두 번째로 저장되어있던 직사각형과 i 번째 위치에 있는 직사각형 사이길이에 직사각형 높이를 곱해준다.
					s = (long long)(i- stack.back()-1)*(long long)h[index];

					ans.push_back(s);	//구한 넓이를 저장한다.
					
				}	

			stack.push_back(i);	//stack data에 push 해준다.

		}
		while (!stack.empty())		//반복문을 마치고 stack 에 남아있던 data들로 위와 같은방법으로 넓이를 구해준다
		{
			long long s;
			int index = stack.back();
			stack.pop_back();
			if (stack.size() == 0)
				s = (long long)(n)*(long long)h[index];
			else
				s =(long long)(n -stack.back()-1)*(long long)h[index];

			ans.push_back(s);
		}

		long long max = *max_element(ans.begin(), ans.end());	//구한 넓이들 중에서 가장 큰 값을 출력한다.
		cout << max << '\n';

	}
}