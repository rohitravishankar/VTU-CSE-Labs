
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class OCTAL {

	int num,y;

	public : 
		OCTAL(int);
		int convert();
		int operator +(int);
		friend ostream & operator <<(ostream &,OCTAL &);

};

void main()
{
	int x,k;
	cout<<"Enter Number to Be Converted to Octal : ";
	cin>>x;
	
	OCTAL h = x;
	
	cout<<"\nOctal Value : "<<h;
	cout<<"\n\nEnter Number to be Added to the Octal Number : ";
	cin>>k;

	int y = h + k;

	cout<<"\nSum After Adding Number to Octal : "<<y;
	getch();

}

OCTAL::OCTAL(int x)
{
	num=x;
	y=convert();
}

int OCTAL::convert()
{
	int sum=0,rem,product=1,temp=num;
	while(temp>0)
	{
		rem=temp%8;
		sum+=(product*rem);
		product*=10;
		temp/=8;
	}
	return sum;
}

int OCTAL::operator +(int k)
{
	return num+k;
}

ostream & operator <<(ostream &out,OCTAL &obj)
{
	out<<obj.y;
	return out;
}



