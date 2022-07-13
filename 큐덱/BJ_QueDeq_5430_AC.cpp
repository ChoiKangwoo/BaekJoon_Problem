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

	int T;		//�׽�Ʈ ����
	cin >> T;

	while (T--)		//�׽�Ʈ ������ŭ ����
	{
		string p = "";	//����Լ��� �޴� ���ڿ� p
		cin >> p;

		int n;		//�迭 ������ ������ �޴� n
		cin >> n;

		string temp = "";		//���ڿ��� split �ϴ� ��
		cin >> temp;		//�ӽ� ���ڿ��� temp �� �Է¹޴´�
		string buff;		//���� ������ �ϴ� ���ڿ�
		istringstream ss(temp);		//�Է����θ� ����ϴ� ���ڿ� ss ����,temp ����
		deque <string> dq;		//�������� ���ڿ��� �����ϴ� dq ����

		//',' �� �����ڷ� ����Ͽ� dq ���ڿ� ���� �Է� ��Ų��
		while (getline(ss, buff, ',')) {
			dq.push_back(buff);
		}

		dq[0].erase(dq[0].begin());		//dq �� ù��° ���ҿ��� "[n" �̷������� ����Ǿ� �ִ� ���� '['�� ������Ű�� ����̴�.
		dq[dq.size() - 1].pop_back();	//dq �� ������ ���ҿ��� "n]" ���� ����Ǿ������Ƿ� ']' ����

		int head = 0;  //Ȧ���̸� index=front �� �� ��, ¦���̸� index=back �� �� ��
		int error = 0;	//error �� �Ǵ��ϴ� ���� error �� ���� ��쿡�� 1�̴�.
		for (int i = 0; i < p.size(); i++)
		{
	
			if (p[i] == 'R')
				R(head);		//�Լ� R ����

			else
			{
				if (dq.size()	==0	||dq[0]=="") //dq[0]="" �� ���� ó������ ũ�Ⱑ 0�� �迭 [ ] �� �Է¹޾��� ���� ����̴�.
					//�� ��� pop �� �� ���� �����Ƿ� dq.size()�� 1�̱� ������ Ư���� ���̽��� ������ ���̴�.
				{
					error++;
					break;
				}
				D(dq, head);		//error ���̽��� �ƴ� ��쿡 �Լ� D ����
			}
		}

		if (error==1)		//error �� ��쿡�� "error" ����Ѵ�.
			cout << "error";
		else
		{
			cout << '[';
			if(head%2==0)		//�迭 ������ �������� ���
			for (int i = 0; i < dq.size(); i++)
			{
				if (i == 0)
					cout << dq[i];
				else
					cout << ',' << dq[i];
			}
			else            //�迭 ������ �������� ���
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

void R(int &head)		//�迭�� ������ �����ִ� �Լ��̴�.
{
	head++;		//head�� Ȧ���� ���=������, ¦���� ���=������
}

void D(deque <string> &dq,int head)		//�迭�� ������ ����Ͽ� pop�� �Ѵ�.
{
	if (head % 2 == 0)
		dq.pop_front();
	else
		dq.pop_back();
}