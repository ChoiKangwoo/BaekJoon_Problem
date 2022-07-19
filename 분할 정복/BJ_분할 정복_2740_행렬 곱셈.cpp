/*
수트라센 알고리즘을 이용한 행렬곱 계산 프로그램이다.
백준 사이트에 정해진 범위내에서는 사실 수트라센보다 삼중 for 문을 이용하는게 더 빠르지만
목적은 분할정복을 이용하는것이기 때문에 수트라센 알고리즘을 사용했다.
수트라센 알고리즘은 2^n*2^n 정사각형 행렬에서 사용할 수 있으므로 정사각형 행렬이 안만들어질 경우
임의로 빈 부분에 0을 채워넣어서 계산하고 출력할 때는 나머지 부분을 빼고 출력해야 한다.
그래서 벡터 크기를 128*128로 고정 해놓고 풀었다.
재귀가 중단되는 부분을 1*1 행렬곱계산까지 왔을 때로 설정하였지만, 2*2 행렬곱 으로 코드를 짜는게 더 빠르고, 더 나아가
수트라센 알고리즘보다 삼중포문을 이용한 계산이 더 빠른 임계값 까지 설정하는게 더 효율적이고 빠르다.
*/

#include <iostream>
#include <vector>

using namespace std;

//행렬의 덧셈 함수
void M_A(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = A[i][j] + B[i][j];
}
//행렬의 뺄셈 함수
void M_S(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A[i].size(); j++)
			C[i][j] = A[i][j] - B[i][j];
}
//분할정복을 위한 수트라센 알고리즘
void strassen(vector <vector<int>> &A, vector <vector<int>> &B, vector <vector<int>> &C)
{
	//1*1 행렬일때의 행렬곱 계산
	if (A.size() ==1)
	{
		C[0][0] = A[0][0] * B[0][0];
	}
	//그 외의 행렬곱 계산은 수트라센 알고리즘으로 푼다
	else
	{
		//정사각행렬 A를 4등분한다
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

		//정사각행렬 B를 4등분한다
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

		//정사각행렬 C를 4등분한다
		vector<vector<int>> C11(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C12(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C21(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> C22(A.size() / 2, vector<int>(A.size()/2));

		//수트라센 알고리즘에서 필요한 M1~M7 선언
		vector<vector<int>> M1(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M2(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M3(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M4(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M5(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M6(A.size() / 2, vector<int>(A.size()/2));
		vector<vector<int>> M7(A.size() / 2, vector<int>(A.size()/2));

		//행렬의 덧셈을 받는 X1~X10 선언
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

	//128*128 행렬로 크기 고정(실제로 입력받는 부분 외에 다 0으로 채우기 위함)
	vector <vector<int>> A(128, vector<int>(128,0));
	vector <vector<int>> B(128, vector<int>(128, 0));
	vector <vector<int>> C(128, vector<int>(128, 0));
	int N, M, K;

	cin >> N >> M;
	//A 행렬
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	//B행렬
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
	//행렬곱 계산
	strassen(A, B, C);

	//실 입력부분만 행렬곱 계산값을 출력
	for(int i=0;i<N;i++)
		for (int j = 0; j < K; j++)
		{
			cout << C[i][j] << ' ';
			if (j == K - 1)
				cout << '\n';
		}


}

