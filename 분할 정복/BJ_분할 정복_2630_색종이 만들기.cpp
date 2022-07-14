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

	vector <vector<int>> v(N, vector<int>(N));		//2���� ���� ����

	for (int i = 0; i < N; i++)		//���� �ʱ�ȭ
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	cut(v, 0, 0, N);		//���� �ڸ��� �Լ� ȣ��

	cout << square_0 << '\n';
	cout << square_1;

}

void cut(vector<vector <int>> v, int start_c,int start_r,int size)
{
	int temp = v[start_r][start_c];		//��Ģ�� �Ǵ��ϴ� ���� temp
	int error = 0;		//����Լ� ȣ�� ���θ� �����ϴ� ���� error

	for (int i = start_r; i < start_r + size; i++)
		for (int j = start_c; j < start_c + size; j++)
			if (temp != v[i][j])		//�ϳ��� temp ���� �ٸ��ٸ� error++
			{
				error++;
				break;
			}

	if (error == 0)		//��� ���� ��ġ�Ѵٸ� ���簢������ �Ǵ�
	{
		if (temp == 0)
			square_0++;
		else
			square_1++;
	}
	else   //���簢���� 4 ������� ������ ����Լ� ����
	{
		cut(v, start_c, start_r, size / 2);
		cut(v, start_c+size/2, start_r, size / 2);
		cut(v, start_c, start_r+size/2, size / 2);
		cut(v, start_c+size/2, start_r+size/2, size / 2);
	}
}