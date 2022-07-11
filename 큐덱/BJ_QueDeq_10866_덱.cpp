#include <iostream>
#include <string>

using namespace std;
const int MAX_SIZE = 20000;		//�ִ� ��ɼ��� ���� �迭�� �ִ�ũ��

class Deque
{
	int data[MAX_SIZE] = { 0 };		//Deque �������
	int first;		//�迭�� �� �� �ε���
	int last;		//�迭�� �� �� �ε���

public:
	Deque()
	{
		first = 10000;	
		last = 9999;
	}

	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	int size();
	int empty();
	int front();
	int back();
};

int main()
{
	int N;
	cin >> N;

	Deque q;

	while (N--)
	{
		string command = "";
		cin >> command;

		if (command == "push_back")
		{
			int n;
			cin >> n;
			q.push_back(n);
		}

		else if (command == "push_front")
		{
			int n;
			cin >> n;
			q.push_front(n);
		}

		else if (command == "pop_front")
			cout << q.pop_front() << '\n';

		else if (command == "pop_back")
			cout << q.pop_back() << '\n';

		else if (command == "size")
			cout << q.size() << '\n';

		else if (command == "empty")
			cout << q.empty() << '\n';

		else if (command == "front")
			cout << q.front() << '\n';

		else if (command == "back")
			cout << q.back() << '\n';
	}
	return 0;


}

void Deque::push_front(int n)
{
	data[--first] = n;		//�ε����� ������ �� ĭ �ű�� �� �Ҵ�
}

void Deque::push_back(int n)
{
	data[++last] = n;		//�ε����� �ڷ� �� ĭ �ű�� �� �Ҵ�
}

int Deque::pop_front()
{
	if (data[first] == 0)		//����Ǿ� �ִ� ���� ������ -1 ���
		return -1;
	else
	{
		int n = data[first];
		data[first++] = 0;		//�Ǿ� �ε����� ��ȯ�ϰ� ���� ���� �ε����� �̵���Ų��.
		return n;
	}
}

int Deque::pop_back()
{
	if (data[last] == 0)
		return -1;
	else
	{
		int n = data[last];
		data[last--] = 0;		//�� �� �ε����� ����ϰ� ���� ���� �ε����� �̵���Ų��.
		return n;
	}
}

int Deque::size()
{
	return last - first + 1;
}

int Deque::empty()		//����Ǿ� �ִ� ���� ������ 1, �ƴ� ��쿡�� 0 ��ȯ
{
	if (Deque::size() == 0)
		return 1;
	else
		return 0;
}

int Deque::front()		//����Ǿ� �ִ� ���� ������ �� ���� ����, �ƴ� ��쿡�� -1 ��ȯ
{
	if (Deque::size() == 0)
		return -1;
	else
		return data[first];
}

int Deque::back()		//����Ǿ� �ִ� ���� ������ �� ���� ����, �ƴ� ��쿡�� -1 ��ȯ
{
	if (Deque::size() == 0)
		return -1;
	else
		return data[last];
}