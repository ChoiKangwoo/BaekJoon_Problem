#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main()
{
	int N;
	cin >> N;

	int M;
	cin >> M;

	deque <int> q;

	for (int i = 0; i < N; i++)
	{
		q.push_back(i + 1);
	}

	vector <int> m;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		m.push_back(n);
	}
	int i = 0;

	int count = 0;

	while (M--)
	{
		for (int j = 0; j < q.size(); j++)
		{
			if (q[j] == m[i])
			{
				if (j > q.size() / 2)		//3번 연산 수행
				{
					for (int x = 0; x < q.size() - j; x++)
					{
						q.push_front(q.back());
						q.pop_back();
						count++;
					}
					break;
				}

				else if (j <=q.size() / 2)		//2번 연산 수행
				{
					for (int x = 0; x < j ; x++)
					{
						q.push_back(q.front());
						q.pop_front();
						count++;
					}
					break;
				}

			}

		}
		q.pop_front();
		i++;
	}
	cout << count;
}