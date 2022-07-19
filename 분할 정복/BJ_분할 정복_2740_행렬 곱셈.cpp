/*
��Ʈ�� �˰����� �̿��� ��İ� ��� ���α׷��̴�.
���� ����Ʈ�� ������ ������������ ��� ��Ʈ�󼾺��� ���� for ���� �̿��ϴ°� �� ��������
������ ���������� �̿��ϴ°��̱� ������ ��Ʈ�� �˰����� ����ߴ�.
��Ʈ�� �˰����� 2^n*2^n ���簢�� ��Ŀ��� ����� �� �����Ƿ� ���簢�� ����� �ȸ������ ���
���Ƿ� �� �κп� 0�� ä���־ ����ϰ� ����� ���� ������ �κ��� ���� ����ؾ� �Ѵ�.
�׷��� ���� ũ�⸦ 128*128�� ���� �س��� Ǯ����.
��Ͱ� �ߴܵǴ� �κ��� 1*1 ��İ������� ���� ���� �����Ͽ�����, 2*2 ��İ� ���� �ڵ带 ¥�°� �� ������, �� ���ư�
��Ʈ�� �˰��򺸴� ���������� �̿��� ����� �� ���� �Ӱ谪 ���� �����ϴ°� �� ȿ�����̰� ������.
*/

#include <iostream>
#include <vector>

using namespace std;

//����� ���� �Լ�
void M_A(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = A[i][j] + B[i][j];
}
//����� ���� �Լ�
void M_S(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = A[i][j] - B[i][j];
}
//���������� ���� ��Ʈ�� �˰���
void strassen(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	//1*1 ����϶��� ��İ� ���
	if (A.size() ==1)
	{
		C[0][0] = A[0][0] * B[0][0];
	}
	//�� ���� ��İ� ����� ��Ʈ�� �˰������� Ǭ��
	else
	{
		//���簢��� A�� 4����Ѵ�
		vector<vector<int>> A11(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < A11.size(); i++)
			for (int j = 0; j < A11.size(); j++)
				A11[i][j] = A[i][j];
		vector<vector<int>> A12(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < A12.size(); i++)
			for (int j = 0; j < A12.size(); j++)
				A12[i][j] = A[i][j + A12.size()];
		vector<vector<int>> A21(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < A21.size(); i++)
			for (int j = 0; j < A21.size(); j++)
				A21[i][j] = A[i + A21.size()][j];
		vector<vector<int>> A22(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < A22.size(); i++)
			for (int j = 0; j < A22.size(); j++)
				A22[i][j] = A[i + A22.size()][j + A22.size()];

		//���簢��� B�� 4����Ѵ�
		vector<vector<int>> B11(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < B11.size(); i++)
			for (int j = 0; j < B11.size(); j++)
				B11[i][j] = B[i][j];
		vector<vector<int>> B12(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < A12.size(); i++)
			for (int j = 0; j < A12.size(); j++)
				B12[i][j] = B[i][j + B12.size()];
		vector<vector<int>> B21(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < B21.size(); i++)
			for (int j = 0; j < B21.size(); j++)
				B21[i][j] = B[i + A21.size()][j];
		vector<vector<int>> B22(A.size() / 2, vector<int>(A.size()/2));
		for (int i = 0; i < B22.size(); i++)
			for (int j = 0; j < B22.size(); j++)
				B22[i][j] = B[i + A22.size()][j + B22.size()];

		//���簢��� C�� 4����Ѵ�
		vector<vector<int>> C11(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C12(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C21(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C22(A.size() / 2, vector<int>(A.size()/2));

		//��Ʈ�� �˰��򿡼� �ʿ��� M1~M7 ����
		vector<vector<int>> M1(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M2(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M3(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M4(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M5(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M6(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M7(A.size() / 2, vector<int>(A.size()/2));

		//����� ������ �޴� X1~X10 ����
		//A11+A22
		vector<vector<int>> X1(A.size() / 2, vector<int>(A.size()/2));
		M_A(A11, A22, X1);
		//B11+B22
		vector<vector<int>> X2(A.size() / 2, vector<int>(A.size()/2));
		M_A(B11, B22, X2);
		//A21+A22
		vector<vector<int>> X3(A.size() / 2, vector<int>(A.size()/2));
		M_A(A21, A22, X3);
		//B12-B22
		vector<vector<int>> X4(A.size() / 2, vector<int>(A.size()/2));
		M_S(B12, B22, X4);
		//B21-B11
		vector<vector<int>> X5(A.size() / 2, vector<int>(A.size()/2));
		M_S(B21, B11, X5);
		//A11+A12
		vector<vector<int>> X6(A.size() / 2, vector<int>(A.size()/2));
		M_A(A11, A12, X6);
		//A21-A11
		vector<vector<int>> X7(A.size() / 2, vector<int>(A.size()/2));
		M_S(A21, A11, X7);
		//B11+B12
		vector<vector<int>> X8(A.size() / 2, vector<int>(A.size()/2));
		M_A(B11, B12, X8);
		//A12-A22
		vector<vector<int>> X9(A.size() / 2, vector<int>(A.size()/2));
		M_S(A12, A22, X9);
		//B21+B22
		vector<vector<int>> X10(A.size() / 2, vector<int>(A.size()/2));
		M_A(B21, B22, X10);


		//1*1 ��İ� ����� ���� ������ ����Լ��� ȣ���Ѵ�
		strassen(X1, X2, M1);
		strassen(X3, B11, M2);
		strassen(A11, X4, M3);
		strassen(A22, X5, M4);
		strassen(X6, B22, M5);
		strassen(X7, X8, M6);
		strassen(X9, X10, M7);


		//C11 ���
		M_A(M1, M4, C11);	M_S(C11, M5, C11);	M_A(C11, M7, C11);
		//C12 ���
		M_A(M3, M5, C12);
		//C21 ���
		M_A(M2, M4, C21);
		//C22 ���
		M_A(M1, M3, C22);	M_S(C22, M2, C22);	M_A(C22, M6, C22);

		//C11 C12 C21 C22 �� C �� ��ġ��
		for (int i = 0; i < C11.size() ; i++)
			for (int j = 0; j < C11.size(); j++)
				C[i][j] = C11[i][j];

		for (int i = 0; i < C12.size(); i++)
			for (int j =0; j < C12.size(); j++)
				C[i][j+C12.size()] = C12[i][j];

		for (int i = 0; i < C21.size(); i++)
			for (int j = 0; j < C21.size(); j++)
				C[i+C21.size()][j] = C21[i][j];

		for (int i = 0; i < C22.size(); i++)
			for (int j = 0; j < C22.size(); j++)
				C[i+C22.size()][j+C22.size()] = C22[i][j];
	}


}

int main()
{
	cin.tie(NULL);

	//128*128 ��ķ� ũ�� ����(������ �Է¹޴� �κ� �ܿ� �� 0���� ä��� ����)
	vector <vector<int>> A(128, vector<int>(128,0));
	vector <vector<int>> B(128, vector<int>(128, 0));
	vector <vector<int>> C(128, vector<int>(128, 0));
	int N, M, K;

	cin >> N >> M;
	//A ���
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	//B���
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
	//��İ� ���
	strassen(A, B, C);

	//�� �Էºκи� ��İ� ��갪�� ���
	for(int i=0;i<N;i++)
		for (int j = 0; j < K; j++)
		{
			cout << C[i][j] << ' ';
			if (j == K - 1)
				cout << '\n';
		}


}

