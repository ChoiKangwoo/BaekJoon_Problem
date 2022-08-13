#include <iostream>
#include <algorithm>

//DP+DFS �� �̿��� Ǯ�̹��

using namespace std;

int M, N;	
int map[500][500];	//������ �� ���������� ���̸� ����
int memory[500][500];		//memory[y][x] ���� �������������� ����� ���� ����

//(x,y) �κ��� �����¿�� ��ǥ�̵��� ���� �迭 
int move_x[4] = { 1,0,-1,0 };
int move_y[4] = { 0,1,0,-1 };

int dfs(int y, int x)
{
	//�������� 1 : ���������� �������� �� �˸��� ��η� �Ǵ��Ͽ� '1' �� ��ȯ�Ѵ�.
	if (y == M - 1 && x == N - 1)
		return 1;
	//�������� 2 : �̹� memory�� ���� ���� �� ���
	if (memory[y][x] != -1)
		return memory[y][x];

	//���߿� memory�� -1�� ��ȯ���� �ʵ���(��η� �������� �ʾ��� ��) 0���� �ʱ�ȭ ���ش�.
	memory[y][x] = 0;

	//��ǥ�� �����¿� �̵�
	for (int k = 0; k < 4; k++)
	{
		int ny = y + move_y[k];
		int nx = x + move_x[k];

		//�̵��� ��ǥ�� map ���� ���� �ְ� ���������� ������ �������� ��
		if (0 <= ny && ny < M && 0 <= nx && nx < N&&map[ny][nx] < map[y][x])
			//���� ����� ���� �����ش�.
			memory[y][x] += dfs(ny, nx);

		//��η� �������� ���� ���
		else
			memory[y][x] += 0;
	}

	//���ȣ���� ������ ���� memory ���� ��ȯ�Ѵ�.
	return memory[y][x];

}

int main()
{
	cin.tie(NULL);

	cin >> M >> N;
	//memory ���� -1�� ���� �ʱ�ȭ
	//0���� �ٷ� �ʱ�ȭ ���� �ʴ� ������ �޸����̼��� ����� �����ϰ� Ȱ���ϱ� �����̴�.
	fill_n(&memory[0][0], 500 * 500, -1);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	//bottom to top �� dp ��� �̹Ƿ� ���������� �Լ� ȣ��
	cout << dfs(0, 0);

}