#include <iostream>
#include <vector>

using namespace std;
void ZIP(vector<vector<char>> &v, int start_r, int start_c, int size);

int main()
{
	cin.tie(NULL);

	int N;		//������ ũ��
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N));	//2���� ���ڿ�����

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	ZIP(v, 0, 0, N);		//���� �Լ� ȣ��


}

void ZIP(vector<vector<char>> &v, int start_r, int start_c, int size)
{
	char temp = v[start_r][start_c];		//�����ϰ��� �ϴ°�
	int error = 0;		//������ �ȵǴ� ��츦 �Ǻ��ϱ� ���� ����

	for(int i=start_r;i<start_r+size;i++)
		for (int j = start_c; j < start_c + size; j++)
		{
			if (temp != v[i][j])		//������ �ȵǴ� ���
			{
				error++;
				break;
			}
		}

	if (error == 0)		//������ �ȴٸ� ���ప�� ����Ѵ�.
		cout << temp;
	else		//������ �ȵȴٸ� �������� ����� �ٽ� �����ϰ� "( )" �� ���Ѵ�
	{
		cout << '(';
		ZIP(v, start_r, start_c, size / 2);
		ZIP(v, start_r, start_c+size/2, size / 2);
		ZIP(v, start_r+size/2, start_c, size / 2);
		ZIP(v, start_r+size/2, start_c+size/2, size / 2);
		cout << ')';
	}

}