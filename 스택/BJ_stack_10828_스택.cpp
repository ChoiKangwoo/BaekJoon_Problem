#include <iostream>
#include <string>
using namespace std;
int stack[10000] = { 0 };
int index = 0;

void push(int X);
int pop();
int size();
int empty();
int top();

int main()
{
	int N;
	cin >> N;


	while (N--)
	{
		string command="";
		cin >> command;

		if (command== "push")
		{
			int X;
			cin >> X;
			push(X);
		}

		else if (command == "pop")
			cout<< pop()<<'\n';

		else if (command == "size")
			 cout<<size()<< '\n';

		else if (command == "empty")
			cout<<empty()<< '\n';

		else if (command == "top")
			cout<<top()<< '\n';
	}

}

void push (int X)
{
	stack[index] = X;
	index++;
}

int pop()
{
	if (stack[0] == 0)
		return -1;
	else
	{
		int temp = stack[index-1];
		stack[index-1] = 0;
		
			index--;
		return temp;
	}

}

int size()
{
	return index;
}

int empty()
{
	if (stack[0] == 0)
		return 1;
	else
		return 0;
}

int top()
{
	if (stack[0] == 0)
		return -1;
	else
		return stack[index-1];
}

