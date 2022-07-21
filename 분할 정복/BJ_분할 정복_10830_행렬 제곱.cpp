#include <iostream>
#include <vector>

using namespace std;

//����� ���� �Լ�
void M_A(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = (A[i][j] + B[i][j]);
}
//����� ���� �Լ�
void M_S(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = (A[i][j] - B[i][j]);
}

//���� col �� row �� ���� ����� �ɰ� ������ ���Ͽ� �ɰ��� ����� ��ȯ�ϴ� �Լ�
vector <vector<int>> split_matrix(vector<vector<int>>&A, int col, int row)
{
	vector<vector<int>> partition(A.size() / 2, vector<int>(A.size() / 2));
	for (int i = 0; i < partition.size(); i++)
		for (int j = 0; j < partition.size(); j++)
			partition[i][j] = A[i + partition.size()*col][j + partition.size()*row];

	return partition;
}

//��Ʈ�� ��� ���� �˰��� 
void strassen(vector<vector<int>> &A, vector <vector<int>>&B, vector<vector<int>> &C)
{
	if (A.size() == 1)
		C[0][0] = A[0][0] * B[0][0];
	else
	{
		vector<vector<int>> A11 = split_matrix(A, 0, 0);
		vector<vector<int>> A12 = split_matrix(A, 0, 1);
		vector<vector<int>> A21 = split_matrix(A, 1, 0);
		vector<vector<int>> A22 = split_matrix(A, 1, 1);

		vector<vector<int>> B11 = split_matrix(B, 0, 0);
		vector<vector<int>> B12 = split_matrix(B, 0, 1);
		vector<vector<int>> B21 = split_matrix(B, 1, 0);
		vector<vector<int>> B22 = split_matrix(B, 1, 1);

		vector < vector<int>> C11(A.size() / 2, vector<int>(A.size() / 2));
		vector < vector<int>> C12(A.size() / 2, vector<int>(A.size() / 2));
		vector < vector<int>> C21(A.size() / 2, vector<int>(A.size() / 2));
		vector < vector<int>> C22(A.size() / 2, vector<int>(A.size() / 2));

		vector<vector<int>>M1(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M2(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M3(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M4(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M5(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M6(A.size() / 2, vector<int>(A.size() / 2));
		vector<vector<int>>M7(A.size() / 2, vector<int>(A.size() / 2));

		//����� ������ �޴� X1~X10 ����
		//A11+A22
		vector<vector<int>> X1(A.size() / 2, vector<int>(A.size() / 2));
		M_A(A11, A22, X1);
		//B11+B22
		vector<vector<int>> X2(A.size() / 2, vector<int>(A.size() / 2));
		M_A(B11, B22, X2);
		//A21+A22
		vector<vector<int>> X3(A.size() / 2, vector<int>(A.size() / 2));
		M_A(A21, A22, X3);
		//B12-B22
		vector<vector<int>> X4(A.size() / 2, vector<int>(A.size() / 2));
		M_S(B12, B22, X4);
		//B21-B11
		vector<vector<int>> X5(A.size() / 2, vector<int>(A.size() / 2));
		M_S(B21, B11, X5);
		//A11+A12
		vector<vector<int>> X6(A.size() / 2, vector<int>(A.size() / 2));
		M_A(A11, A12, X6);
		//A21-A11
		vector<vector<int>> X7(A.size() / 2, vector<int>(A.size() / 2));
		M_S(A21, A11, X7);
		//B11+B12
		vector<vector<int>> X8(A.size() / 2, vector<int>(A.size() / 2));
		M_A(B11, B12, X8);
		//A12-A22
		vector<vector<int>> X9(A.size() / 2, vector<int>(A.size() / 2));
		M_S(A12, A22, X9);
		//B21+B22
		vector<vector<int>> X10(A.size() / 2, vector<int>(A.size() / 2));
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
		for (int i = 0; i < C11.size(); i++)
			for (int j = 0; j < C11.size(); j++)
				C[i][j] = C11[i][j];

		for (int i = 0; i < C12.size(); i++)
			for (int j = 0; j < C12.size(); j++)
				C[i][j + C12.size()] = C12[i][j];

		for (int i = 0; i < C21.size(); i++)
			for (int j = 0; j < C21.size(); j++)
				C[i + C21.size()][j] = C21[i][j];

		for (int i = 0; i < C22.size(); i++)
			for (int j = 0; j < C22.size(); j++)
				C[i + C22.size()][j + C22.size()] = C22[i][j];
	}
}

//����� �ŵ������� A^2 �÷� �ٲپ� ���������ϴ� �Լ�
vector<vector<int>> square(vector<vector<int>>&A, long long size, int K)
{
	if (size == 1)
	{
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < A.size(); j++)
				A[i][j] = A[i][j] % 1000;	//���Ұ��� 1000�� ��츦 ���� ��ⷯ ����
		return A;
	}

	else
	{
		vector<vector<int>> temp = square(A, size / 2, K);	//�ŵ����� ������ ��������� ȣ���Ͽ� temp�� ����

		if (size % 2)	//�ŵ������� Ȧ �� �� �� ��
		{
			vector<vector<int>> C(A.size(), vector<int>(A.size()));
			strassen(temp, temp, C);	//temp*temp ���� =A^2
			for (int i = 0; i < C.size(); i++)
				for (int j = 0; j < C.size(); j++)
					C[i][j] %= 1000;

			vector<vector<int>>X(A.size(), vector<int>(A.size()));
			strassen(A, C, X);//���갪�� A����� �����ش�.
			for (int i = 0; i < X.size(); i++)
				for (int j = 0; j < X.size(); j++)
					X[i][j] %= 1000;
			return X;
		}
		else
		{
			vector<vector<int>> X(A.size(), vector<int>(A.size()));
			strassen(temp, temp, X);	//temp*temp ����=A^2
			for (int i = 0; i < X.size(); i++)
				for (int j = 0; j < X.size(); j++)
					X[i][j] %= 1000;
			return X;
		}
	}



}


int main()
{
	int N;
	cin >> N;		//N*N ���

	long long B;
	cin >> B;		//������

	int K = 2;
	while (K < N)	//������ ���簢����� ��������� K ����
		K = K * 2;

	vector <vector <int>> A(K, vector<int>(K, 0));		//K*K ���

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	vector<vector<int>> C(K, vector<int>(K));

	C = square(A, B, K);

	//�� �Էºκи� ��İ� ��갪�� ���
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cout << C[i][j] << ' ';
			if (j == N - 1)
				cout << '\n';
		}


}