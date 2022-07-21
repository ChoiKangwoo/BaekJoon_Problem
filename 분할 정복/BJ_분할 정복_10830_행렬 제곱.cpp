#include <iostream>
#include <vector>

using namespace std;

//행렬의 덧셈 함수
void M_A(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = (A[i][j] + B[i][j]);
}
//행렬의 뺄셈 함수
void M_S(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = (A[i][j] - B[i][j]);
}

//인자 col 과 row 에 따라서 행렬을 쪼갤 범위를 정하여 쪼개진 행렬을 반환하는 함수
vector <vector<int>> split_matrix(vector<vector<int>>&A, int col, int row)
{
	vector<vector<int>> partition(A.size() / 2, vector<int>(A.size() / 2));
	for (int i = 0; i < partition.size(); i++)
		for (int j = 0; j < partition.size(); j++)
			partition[i][j] = A[i + partition.size()*col][j + partition.size()*row];

	return partition;
}

//쉬트라센 행렬 곱셈 알고리즘 
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

		//행렬의 덧셈을 받는 X1~X10 선언
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


		//1*1 행렬곱 계산이 나올 때까지 재귀함수로 호출한다
		strassen(X1, X2, M1);
		strassen(X3, B11, M2);
		strassen(A11, X4, M3);
		strassen(A22, X5, M4);
		strassen(X6, B22, M5);
		strassen(X7, X8, M6);
		strassen(X9, X10, M7);


		//C11 계산
		M_A(M1, M4, C11);	M_S(C11, M5, C11);	M_A(C11, M7, C11);
		//C12 계산
		M_A(M3, M5, C12);
		//C21 계산
		M_A(M2, M4, C21);
		//C22 계산
		M_A(M1, M3, C22);	M_S(C22, M2, C22);	M_A(C22, M6, C22);

		//C11 C12 C21 C22 를 C 로 합치기
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

//행렬의 거듭제곱을 A^2 꼴로 바꾸어 분할정복하는 함수
vector<vector<int>> square(vector<vector<int>>&A, long long size, int K)
{
	if (size == 1)
	{
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < A.size(); j++)
				A[i][j] = A[i][j] % 1000;	//원소값이 1000인 경우를 위한 모듈러 연산
		return A;
	}

	else
	{
		vector<vector<int>> temp = square(A, size / 2, K);	//거듭제곱 연산을 재귀적으로 호출하여 temp에 저장

		if (size % 2)	//거듭제곱을 홀 수 번 할 때
		{
			vector<vector<int>> C(A.size(), vector<int>(A.size()));
			strassen(temp, temp, C);	//temp*temp 연산 =A^2
			for (int i = 0; i < C.size(); i++)
				for (int j = 0; j < C.size(); j++)
					C[i][j] %= 1000;

			vector<vector<int>>X(A.size(), vector<int>(A.size()));
			strassen(A, C, X);//연산값에 A행렬을 곱해준다.
			for (int i = 0; i < X.size(); i++)
				for (int j = 0; j < X.size(); j++)
					X[i][j] %= 1000;
			return X;
		}
		else
		{
			vector<vector<int>> X(A.size(), vector<int>(A.size()));
			strassen(temp, temp, X);	//temp*temp 연산=A^2
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
	cin >> N;		//N*N 행렬

	long long B;
	cin >> B;		//제곱수

	int K = 2;
	while (K < N)	//최적의 정사각행렬을 만들기위한 K 선언
		K = K * 2;

	vector <vector <int>> A(K, vector<int>(K, 0));		//K*K 행렬

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	vector<vector<int>> C(K, vector<int>(K));

	C = square(A, B, K);

	//실 입력부분만 행렬곱 계산값을 출력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cout << C[i][j] << ' ';
			if (j == N - 1)
				cout << '\n';
		}


}