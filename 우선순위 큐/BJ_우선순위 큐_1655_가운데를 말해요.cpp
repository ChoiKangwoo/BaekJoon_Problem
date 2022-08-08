#include <iostream>
#include<queue>
#include <vector>

using namespace std;

//중간값 mid 보다 낮은 수들을 저장하는 큐
priority_queue<int, vector<int> > lower;
//mid 보다 높은 수들을 저장하는 큐
priority_queue<int, vector<int>, greater<int>> upper;


int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;

	int x;
	int mid;		//중간값
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (i == 0)
			mid = x;

		//새로 입력한 x가 mid 보다 클때
		else if (mid < x)
		{
			//lower 사이즈가 더 큰 경우는 없다.

			//lower 큐와 upper 큐가 서로 같은 사이즈 일때
			if (lower.size() == upper.size())
				upper.push(x);		//mid 값은 바뀌지 않은채로 upper 에 수 저장

			//사이즈가 upper 큐가 더 크다면
			else if (lower.size() < upper.size())
			{
				//lower 큐 쪽으로 한칸 씩 땡겨온다. (mid 값 바뀐다.)
				lower.push(mid);
				upper.push(x);
				mid = upper.top();
				upper.pop();
			}

		}

		//x가 mid 보다 작거나 같을 때
		else if (x <= mid)
		{
			//lower 사이즈가 더 큰 경우는 없다.

			//서로 같은 사이즈 일때
			if (lower.size() == upper.size())
			{
				//upper 큐 쪽으로 한 칸 씩 땡겨온다. (mid 값 바뀐다.)
				upper.push(mid);
				lower.push(x);
				mid = lower.top();
				lower.pop();
			}
			//upper 사이즈가 더 클때
			else if (lower.size() < upper.size())
				lower.push(x);	//mid 값이 바뀌지 않은채로 x 값을 push 한다.

		}

		cout << mid << '\n';

	}


}