#include <iostream>
#include <vector>

using namespace std;
int square_0 = 0;
int square_1 = 0;
void cut(vector<vector <int>> v, int start_c, int start_r, int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <vector<int>> v(N, vector<int>(N));		//2차원 벡터 생성

	for (int i = 0; i < N; i++)		//벡터 초기화
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	cut(v, 0, 0, N);		//종이 자르기 함수 호출

	cout << square_0 << '\n';
	cout << square_1;

}

void cut(vector<vector <int>> v, int start_c,int start_r,int size)
{
	int temp = v[start_r][start_c];		//규칙을 판단하는 변수 temp
	int error = 0;		//재귀함수 호출 여부를 결정하는 변수 error

	for (int i = start_r; i < start_r + size; i++)
		for (int j = start_c; j < start_c + size; j++)
			if (temp != v[i][j])		//하나라도 temp 값과 다르다면 error++
			{
				error++;
				break;
			}

	if (error == 0)		//모든 값이 일치한다면 정사각형으로 판단
	{
		if (temp == 0)
			square_0++;
		else
			square_1++;
	}
	else   //정사각형을 4 등분으로 나누어 재귀함수 실행
	{
		cut(v, start_c, start_r, size / 2);
		cut(v, start_c+size/2, start_r, size / 2);
		cut(v, start_c, start_r+size/2, size / 2);
		cut(v, start_c+size/2, start_r+size/2, size / 2);
	}
}