#include <iostream>
#include <algorithm>

using namespace std;

int N;
int memory[31][15001];
int weight[31];

void knapsack(int i, int w)
{
	if (N < i)
		return;
	if (memory[i][w])
		return;
	
	memory[i][w] = 1;

	knapsack(i + 1, w);
	knapsack(i + 1, w + weight[i]);
	knapsack(i + 1, abs(w - weight[i]));

}
int main()
{
	cin >> N;	//구슬의 개수

	for (int i = 0; i < N; i++)
		cin >> weight[i];

	knapsack(0, 0);

	int M;
	cin >> M;

	int m;
	for (int i = 0; i < M; i++)
	{
		cin >> m;
		if (m > 15000)	cout << "N ";
		else if (memory[N][m])	cout << "Y ";
		else cout << "N ";
	}



}