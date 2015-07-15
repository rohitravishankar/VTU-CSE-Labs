
#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>

#define MAX 5

using namespace std;

class STACK {

	int top;
	int arr[MAX];

	public:
		STACK();
		STACK operator + (int);
		STACK operator -- ();
		friend void operator <<(ostream &,STACK &);

};

void main()
{
	STACK s1;
	int ch,ele;
	
	while(true)
	{
		system("cls");
		cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\nEnter The Element to Push : ";
			cin>>ele;
			s1 = s1 + ele;
			cout<<"\n"<<s1;
			break;
		case 2:s1 = --s1;
			cout<<"\n"<<s1;
			break;
		case 3:cout<<"\n"<<s1;
			break;
		case 4:exit(0);
			break;
		default:cout<<"\nInvalid Selection\n";
		}
		getch();
	}
}

STACK::STACK()
{
	top=-1;
}

STACK STACK::operator +(int ele)
{
	if(top==MAX-1)
	{
		cout<<"\nSTACK Overflow";
		return *this;
	}

	arr[++top]=ele;
	return *this;
}


STACK STACK::operator --()
{
	if(top==-1)
	{
		cout<<"\nSTACK Underflow\n";
		return *this;
	}

	cout<<"\nThe Popped Element is : "<<arr[top--]<<"\n";
	return *this;
}


void operator <<(ostream &out,STACK &s)
{
	if(s.top==-1)
	{
		out<<"\nSTACK Empty";
		return;
	}

	cout<<"\nThe Current Contents of STACK Are : ";
	for(int i = s.top ; i >= 0 ; i--)
	{
		out<<s.arr[i]<<" ";
	}
}



