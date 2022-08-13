#include <iostream>
#include <algorithm>

//DP+DFS 를 이용한 풀이방법

using namespace std;

int M, N;	
int map[500][500];	//지도의 각 지점마다의 높이를 저장
int memory[500][500];		//memory[y][x] 부터 종료지점까지의 경로의 갯수 저장

//(x,y) 로부터 상하좌우로 좌표이동을 위한 배열 
int move_x[4] = { 1,0,-1,0 };
int move_y[4] = { 0,1,0,-1 };

int dfs(int y, int x)
{
	//종료조건 1 : 종료지점에 도착했을 때 알맞은 경로로 판단하여 '1' 을 반환한다.
	if (y == M - 1 && x == N - 1)
		return 1;
	//종료조건 2 : 이미 memory에 값이 존재 할 경우
	if (memory[y][x] != -1)
		return memory[y][x];

	//나중에 memory가 -1을 반환하지 않도록(경로로 인정되지 않았을 때) 0으로 초기화 해준다.
	memory[y][x] = 0;

	//좌표의 상하좌우 이동
	for (int k = 0; k < 4; k++)
	{
		int ny = y + move_y[k];
		int nx = x + move_x[k];

		//이동한 좌표가 map 범위 내에 있고 내리막길인 조건을 만족했을 때
		if (0 <= ny && ny < M && 0 <= nx && nx < N&&map[ny][nx] < map[y][x])
			//누적 경로의 수를 더해준다.
			memory[y][x] += dfs(ny, nx);

		//경로로 인정되지 않은 경우
		else
			memory[y][x] += 0;
	}

	//재귀호출이 끝나면 계산된 memory 값을 반환한다.
	return memory[y][x];

}

int main()
{
	cin.tie(NULL);

	cin >> M >> N;
	//memory 값을 -1로 전부 초기화
	//0으로 바로 초기화 하지 않는 이유는 메모제이션을 제대로 이해하고 활용하기 위함이다.
	fill_n(&memory[0][0], 500 * 500, -1);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	//bottom to top 인 dp 방식 이므로 시작점에서 함수 호출
	cout << dfs(0, 0);

}