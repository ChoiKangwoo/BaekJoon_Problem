#include <iostream>
#include <vector>

using namespace std;
void ZIP(vector<vector<char>> &v, int start_r, int start_c, int size);

int main()
{
	cin.tie(NULL);

	int N;		//한줄의 크기
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N));	//2차원 문자열벡터

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	ZIP(v, 0, 0, N);		//압축 함수 호출


}

void ZIP(vector<vector<char>> &v, int start_r, int start_c, int size)
{
	char temp = v[start_r][start_c];		//압축하고자 하는값
	int error = 0;		//압축이 안되는 경우를 판별하기 위한 변수

	for(int i=start_r;i<start_r+size;i++)
		for (int j = start_c; j < start_c + size; j++)
		{
			if (temp != v[i][j])		//압축이 안되는 경우
			{
				error++;
				break;
			}
		}

	if (error == 0)		//압축이 된다면 압축값을 출력한다.
		cout << temp;
	else		//압축이 안된다면 사등분으로 나누어서 다시 진행하고 "( )" 로 감싼다
	{
		cout << '(';
		ZIP(v, start_r, start_c, size / 2);
		ZIP(v, start_r, start_c+size/2, size / 2);
		ZIP(v, start_r+size/2, start_c, size / 2);
		ZIP(v, start_r+size/2, start_c+size/2, size / 2);
		cout << ')';
	}

}