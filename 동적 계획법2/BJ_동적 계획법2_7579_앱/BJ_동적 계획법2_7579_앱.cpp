#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 111

int N, M, m[MAXN], c[MAXN], DP[10100];

int f() {
	//memory ���� �ʹ� Ŀ �迭�� ���ڰ��� ����� �� ����.
	//�׷� �߻��� ��ȯ�Ͽ� cost�� �迭�� ���ڰ����� �ϰ�
	//memory�� �迭�� �� ������ ��������.

	//�ּ� M�� memory�� Ȯ���� ���¿��� �ּ� cost���� ã���� �ȴ�.

	int size = 0;
	for (int i = 0; i < N; i++) size += c[i];

	for (int i = 0; i < N; i++) {
		// �ڽ�Ʈ


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