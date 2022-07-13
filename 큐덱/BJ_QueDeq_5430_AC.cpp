#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;
void R(int &head);
void D(deque <string> &dq, int head);

int main()
{
	cin.tie(NULL);

	int T;		//테스트 갯수
	cin >> T;

	while (T--)		//테스트 갯수만큼 실행
	{
		string p = "";	//명령함수를 받는 문자열 p
		cin >> p;

		int n;		//배열 원소의 갯수를 받는 n
		cin >> n;

		string temp = "";		//문자열을 split 하는 법
		cin >> temp;		//임시 문자열을 temp 에 입력받는다
		string buff;		//버퍼 역할을 하는 문자열
		istringstream ss(temp);		//입력으로만 사용하는 문자열 ss 선언,temp 복사
		deque <string> dq;		//실질적인 문자열을 저장하는 dq 선언

		//',' 를 구분자로 사용하여 dq 문자열 덱에 입력 시킨다
		while (getline(ss, buff, ',')) {
			dq.push_back(buff);
		}

		dq[0].erase(dq[0].begin());		//dq 의 첫번째 원소에는 "[n" 이런식으로 저장되어 있다 따라서 '['을 삭제시키는 방법이다.
		dq[dq.size() - 1].pop_back();	//dq 의 마지막 원소에는 "n]" 으로 저장되어있으므로 ']' 삭제

		int head = 0;  //홀수이면 index=front 가 맨 앞, 짝수이면 index=back 이 맨 앞
		int error = 0;	//error 를 판단하는 변수 error 가 있을 경우에는 1이다.
		for (int i = 0; i < p.size(); i++)
		{
	
			if (p[i] == 'R')
				R(head);		//함수 R 실행

			else
			{
				if (dq.size()	==0	||dq[0]=="") //dq[0]="" 의 경우는 처음부터 크기가 0인 배열 [ ] 을 입력받았을 때의 경우이다.
					//이 경우 pop 이 된 적이 없으므로 dq.size()는 1이기 때문에 특수한 케이스를 적어준 것이다.
				{
					error++;
					break;
				}
				D(dq, head);		//error 케이스가 아닌 경우에 함수 D 실행
			}
		}

		if (error==1)		//error 일 경우에는 "error" 출력한다.
			cout << "error";
		else
		{
			cout << '[';
			if(head%2==0)		//배열 방향이 정방향일 경우
			for (int i = 0; i < dq.size(); i++)
			{
				if (i == 0)
					cout << dq[i];
				else
					cout << ',' << dq[i];
			}
			else            //배열 방향이 역방향일 경우
			{
				for (int i = dq.size() - 1; i >= 0; i--)
					if (i == dq.size() - 1)
						cout << dq[i];
					else
						cout << ',' << dq[i];
			}
			cout << ']';
		}
		cout << '\n';


	}


}

void R(int &head)		//배열의 방향을 정해주는 함수이다.
{
	head++;		//head가 홀수인 경우=정방향, 짝수인 경우=역방향
}

void D(deque <string> &dq,int head)		//배열의 방향을 고려하여 pop을 한다.
{
	if (head % 2 == 0)
		dq.pop_front();
	else
		dq.pop_back();
}