#include <iostream>
#include <vector>

using namespace std;

int square_m1 = 0;		//-1 ���簢���� ����
int square_0 = 0;			//0 ���簢���� ����
int square_1 = 0;			//1 ���簢���� ����

void cut(vector<vector<int>> &v, int start_r, int start_c, int size);

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;		//������ ũ��

	vector<vector<int>> v(N, vector<int>(N));		//int �� 2���� ���� ����

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	cut(v, 0, 0, N);			//�����ڸ��� �Լ� ȣ��

	cout << square_m1 << '\n';
	cout << square_0 << '\n';
	cout << square_1;

}

void cut(vector<vector<int>> &v, int start_r, int start_c, int size)
{
	int temp = v[start_r][start_c];		//�ش� ���簢�� ������ �����ϴ� ����
	int error = 0;		//���簢���� ������ �ȵǴ� ��츦 �Ǻ�

	for(int i=start_r;i<start_r+size;i++)
		for (int j = start_c; j < start_c + size; j++)
			if (temp != v[i][j])		//���� �� ���� �ٸ��� ���簢���� �������� ����
			{
				error++;		//�� ��쿡 error ���� 1�� �����
				break;
			}

	if (error == 0)		//���簢���� �����Ǵ� ���
	{
		if (temp == -1)		//temp ���� ���� �ش� ���簢���� ������ ������Ų��.
			square_m1++;
		else if (temp == 0)
			square_0++;
		else
			square_1++;
	}

	else			//���簢���� �������� �ʴ� ���� 9������� ����� ����Լ��� �����Ѵ�.
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