#include <iostream>
#include <vector>

using namespace std;

int square_m1 = 0;		//-1 정사각형의 개수
int square_0 = 0;			//0 정사각형의 개수
int square_1 = 0;			//1 정사각형의 개수

void cut(vector<vector<int>> &v, int start_r, int start_c, int size);

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;		//한줄의 크기

	vector<vector<int>> v(N, vector<int>(N));		//int 형 2차원 벡터 선언

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	cut(v, 0, 0, N);			//종이자르기 함수 호출

	cout << square_m1 << '\n';
	cout << square_0 << '\n';
	cout << square_1;

}

void cut(vector<vector<int>> &v, int start_r, int start_c, int size)
{
	int temp = v[start_r][start_c];		//해당 정사각형 형식을 결정하는 변수
	int error = 0;		//정사각형이 형성이 안되는 경우를 판별

	for(int i=start_r;i<start_r+size;i++)
		for (int j = start_c; j < start_c + size; j++)
			if (temp != v[i][j])		//정수 한 개라도 다르면 정사각형이 형성되지 않음
			{
				error++;		//그 경우에 error 값을 1로 만든다
				break;
			}

	if (error == 0)		//정사각형이 형성되는 경우
	{
		if (temp == -1)		//temp 값에 따라서 해당 정사각형의 개수를 증가시킨다.
			square_m1++;
		else if (temp == 0)
			square_0++;
		else
			square_1++;
	}

	else			//정사각형이 형성되지 않는 경우는 9등분으로 나누어서 재귀함수를 실행한다.
	{
		cut(v, start_r, start_c, size / 3);
		cut(v, start_r, start_c+ size / 3, size / 3);
		cut(v, start_r, start_c+ (size / 3)*2, size / 3);
		cut(v, start_r+ size / 3, start_c, size / 3);
		cut(v, start_r+ size / 3, start_c+ size / 3, size / 3);
		cut(v, start_r+ size / 3, start_c+(size / 3)*2, size / 3);
		cut(v, start_r+(size / 3)*2, start_c, size / 3);
		cut(v, start_r + (size / 3) * 2, start_c+ size / 3, size / 3);
		cut(v, start_r + (size / 3) * 2, start_c + (size / 3) * 2, size / 3);
	}

}