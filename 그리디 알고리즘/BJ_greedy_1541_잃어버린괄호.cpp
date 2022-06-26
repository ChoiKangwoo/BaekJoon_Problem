#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;						//식을 받는 string 

	cin >> str;

	int count = 0;				// '-' 부호에 따른 처리를 위한 변수
	int sum = 0;					//최종 합


	for (int i = 0; i < str.length(); i++)
	{
		string temp = "";			//임시 배열을 선언하여 연산자 전까지의 문자열들을 저장
		
		
		while(i<str.length()&&str[i] != '+'&&str[i] != '-')
			temp += str[i++];			//임시 문장에 문자할당하고 i값 증가 (부호 나오기 전까지)
			
		

		if (count == 0)
			sum += stoi(temp);		//sum 에 temp 문자열을 int 형으로 변환해서 더함
		else if (count > 0)
			sum -= stoi(temp);			//한번 이라도 '-' 가 나타났다면 이후의 숫자들은 다 빼기 취급해도 된다.

		if (str[i] == '-')
			count++;							// '-' 가 나왔을 때 count 값 증가시켜 다음에 오는 숫자들을 다 빼기 처리할 수 있도록 도와준다.

	}

	cout << sum;

	return 0;
}