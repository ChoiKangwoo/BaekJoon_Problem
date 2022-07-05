#include <iostream>
#include<stdio.h>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int num[10001] = { 0, };

	int max = 0;

	while (N--) {
		int n;
		scanf("%d", &n);
		num[n]++;
		if (n > max) max = n;
	}

	for (int i = 0; i <= max; i++) {
		for (int k = 0; k < num[i]; k++)
			printf("%d\n", i);
	}

	return 0;

}

