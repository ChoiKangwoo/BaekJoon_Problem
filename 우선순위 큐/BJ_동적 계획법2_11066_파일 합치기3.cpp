#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;

		priority_queue<long long, vector<long long>, greater<long long>>A;
		long long cost = 0;
		int x;
		for (int i = 0; i < K; i++)
		{
			cin >> x;
			A.push(x);
		}

		long long a, b;
		while ( A.size()>1 )
		{
			a = A.top();
			A.pop();
			b = A.top();
			A.pop();

			cost +=a + b;

			A.push(a + b);


		}
		cout << cost << '\n';

	}
}