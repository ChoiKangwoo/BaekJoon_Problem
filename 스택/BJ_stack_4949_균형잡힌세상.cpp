#include<iostream>
#include<string>

using namespace std;

int main()
{
	
		while (1)
		{
			string arr = "";
			getline(cin, arr,'.');		//'.' �� �Է¹����� �Է� ����
			cin.ignore();				//���� ����

			if (arr[0] == NULL)		//�ݺ��� ���� ����
				break;

			char PV[102] = {};

			int index = 0;

			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i] == '(' || arr[i] == ')' || arr[i] == '[' || arr[i] == ']' )
					PV[index++] = arr[i];
				
				if (index > 1 && PV[index - 2] == '('&&PV[index - 1] == ')')
				{
					PV[--index] = NULL;
					PV[--index] = NULL;
				}
				else if(index > 1 && PV[index - 2] == '['&&PV[index - 1] == ']')
				{
					PV[--index] = NULL;
					PV[--index] = NULL;
				}
				
			}
			
			if (PV[0] == NULL)
				cout << "yes" << '\n';		
			else
				cout << "no" << '\n';

		}
	
}