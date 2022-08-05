#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ans;
priority_queue<int, vector<int>, greater<int >> p;
priority_queue<int, vector<int>>m;

//C++ 에서 제공하는 우선순위 큐를 이용하여 문제를 풀었다.
//양수값을 저장하는 큐와 음수값을 저장하는 큐를 따로 만들어서 둘을 비교해 풀었다.

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;
	
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0) {
			if (p.empty() && m.empty())
				ans.push_back(0);
			else
			{
				if (p.empty())
				{
					ans.push_back(m.top());
					m.pop();
				}
				else if (m.empty())
				{
					ans.push_back(p.top());
					p.pop();
				}
				else if (p.top() < -m.top())
				{
					ans.push_back(p.top());
					p.pop();
				}
				else {
					ans.push_back(m.top());
					m.pop();
				}
			}
		}

		else if (x > 0)
			p.push(x);
		else
			m.push(x);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}