#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;						//���� �޴� string 

	cin >> str;

	int count = 0;				// '-' ��ȣ�� ���� ó���� ���� ����
	int sum = 0;					//���� ��


	for (int i = 0; i < str.length(); i++)
	{
		string temp = "";			//�ӽ� �迭�� �����Ͽ� ������ �������� ���ڿ����� ����
		
		
		while(i<str.length()&&str[i] != '+'&&str[i] != '-')
			temp += str[i++];			//�ӽ� ���忡 �����Ҵ��ϰ� i�� ���� (��ȣ ������ ������)
			
		

		if (count == 0)
			sum += stoi(temp);		//sum �� temp ���ڿ��� int ������ ��ȯ�ؼ� ����
		else if (count > 0)
			sum -= stoi(temp);			//�ѹ� �̶� '-' �� ��Ÿ���ٸ� ������ ���ڵ��� �� ���� ����ص� �ȴ�.

		if (str[i] == '-')
			count++;							// '-' �� ������ �� count �� �������� ������ ���� ���ڵ��� �� ���� ó���� �� �ֵ��� �����ش�.

	}

	cout << sum;

	return 0;
}