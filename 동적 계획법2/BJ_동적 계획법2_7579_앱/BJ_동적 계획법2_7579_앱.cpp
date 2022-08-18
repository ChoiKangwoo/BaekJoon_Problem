#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 111

int N, M, m[MAXN], c[MAXN], DP[10100];

int f() {
	//memory 값이 너무 커 배열의 인자값을 사용할 수 없다.
	//그럼 발상을 전환하여 cost를 배열의 인자값으로 하고
	//memory는 배열에 들어갈 값으로 생각하자.

	//최소 M의 memory를 확보한 상태에서 최소 cost값을 찾으면 된다.

	int size = 0;
	for (int i = 0; i < N; i++) size += c[i];

	for (int i = 0; i < N; i++) {
		// 코스트


		for (int j = c[i]; j <= size; j++) {
			DP[j] = max(DP[j], DP[j - c[i]] + m[i]);
		}
	}

	int ans;
	for (int i = 0; i <= size; i++) {
		if (DP[i] >= M) {
			ans = i;
			break;
		}
	}
	return ans;
}


int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &m[i]);
	for (int i = 0; i < N; i++) scanf("%d", &c[i]);

	printf("%d\n", f());

	return 0;
}