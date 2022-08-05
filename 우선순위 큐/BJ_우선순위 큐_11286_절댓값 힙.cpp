#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ans;
priority_queue<int, vector<int>, greater<int >> p;
priority_queue<int, vector<int>>m;

//C++ ���� �����ϴ� �켱���� ť�� �̿��Ͽ� ������ Ǯ����.
//������� �����ϴ� ť�� �������� �����ϴ� ť�� ���� ���� ���� ���� Ǯ����.

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