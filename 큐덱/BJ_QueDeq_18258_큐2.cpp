#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 2000001;

class Que {
	int data[MAX_SIZE] = { 0 };
	int index;
	int first;
public:
	Que(int nindex=-1, int nfirst=0) :index(nindex), first(nfirst) { }
	void push(int n);
	int pop();
	int size();
	int empty();
	int front();
	int back();
};

int main()
{
	ios::sync_with_stdio(false);		//입력버퍼와 출력버퍼의 분리
	cin.tie(NULL);

	int N;		//명령문의 수 입력받기
	cin >> N;

	Que q;		//큐 작업을 수행할 q 선언

	while (N--)		
	{
		string command = "";
		cin >> command;

		if (command == "push")
		{
			int n;
			cin >> n;
			q.push(n);
		}

		else if (command == "pop")
			cout<<q.pop()<<'\n';

		else if (command == "size")
			cout<<q.size()<<'\n';

		else if (command == "empty")
			cout<<q.empty()<<'\n';

		else if (command == "front")
			cout<<q.front()<<'\n';

		else if (command == "back")
			cout<<q.back()<<'\n';
	}

	return 0;
}

void Que::push(int n)	
{
	data[++index] = n;
}

int Que::pop()
{
	if (data[first]==0)
		return -1;
	else
	{
		int n = data[first];
		data[first++] = 0;
		return n;
	}
}

int Que::size()
{
	return index - first + 1;
}

int Que::empty()
{
	if (data[first] == 0)
		return 1;
	else
		return 0;
}

int Que::front()
{
	if (data[first] == 0)
		return -1;
	else
		return data[first];
}

int Que::back()
{
	if (data[first] == 0)
		return -1;
	else
		return data[index];
}