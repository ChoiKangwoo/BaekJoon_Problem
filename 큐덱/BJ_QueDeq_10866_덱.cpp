#include <iostream>
#include <string>

using namespace std;
const int MAX_SIZE = 20000;		//최대 명령수에 따른 배열의 최대크기

class Deque
{
	int data[MAX_SIZE] = { 0 };		//Deque 저장공간
	int first;		//배열의 맨 앞 인덱스
	int last;		//배열의 맨 뒤 인덱스

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
	data[--first] = n;		//인덱스를 앞으로 한 칸 옮기고 값 할당
}

void Deque::push_back(int n)
{
	data[++last] = n;		//인덱스를 뒤로 한 칸 옮기고 값 할당
}

int Deque::pop_front()
{
	if (data[first] == 0)		//저장되어 있는 값이 없으면 -1 출력
		return -1;
	else
	{
		int n = data[first];
		data[first++] = 0;		//맨앞 인덱스를 반환하고 값을 비우고 인덱스를 이동시킨다.
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
		data[last--] = 0;		//맨 뒤 인덱스를 출력하고 값을 비우고 인덱스를 이동시킨다.
		return n;
	}
}

int Deque::size()
{
	return last - first + 1;
}

int Deque::empty()		//저장되어 있는 값이 없으면 1, 아닐 경우에는 0 반환
{
	if (Deque::size() == 0)
		return 1;
	else
		return 0;
}

int Deque::front()		//저장되어 있는 값이 있으면 맨 앞의 값을, 아닐 경우에는 -1 반환
{
	if (Deque::size() == 0)
		return -1;
	else
		return data[first];
}

int Deque::back()		//저장되어 있는 값이 있으면 맨 뒤의 값을, 아닐 경우에는 -1 반환
{
	if (Deque::size() == 0)
		return -1;
	else
		return data[last];
}