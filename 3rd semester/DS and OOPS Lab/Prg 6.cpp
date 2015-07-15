
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

class STRING {

	char *str;
	
	public :
		STRING();
		STRING(char *);
		STRING(const STRING &);
		STRING operator +(STRING &);
		friend ostream & operator <<(ostream &,STRING &);

};

void main()
{
	STRING s1 = "VTU";
	STRING s2 = "BELGAUM";
	STRING s3 = s1 + s2;

	cout<<"s1 = "<<s1<<"\n";
	cout<<"s2 = "<<s2<<"\n";
	cout<<"s3 = "<<s3<<"\n";

	getch();
}

STRING::STRING()
{
	str=NULL;
}

STRING::STRING(char *x)
{
	str=new char[strlen(x)+1];
	strcpy(str,x);
}

STRING::STRING(const STRING &s3)
{
	str=new char[strlen(s3.str)+1];
	strcpy(str,s3.str);
}

STRING STRING::operator +(STRING &s2)
{
	STRING temp;
	
	temp.str=new char[strlen(str)+strlen(s2.str)+1];

	strcpy(temp.str,str);
	strcat(temp.str,s2.str);

	return temp;
}

ostream & operator <<(ostream &out,STRING &s)
{
	out<<s.str<<"\n\n";
	return out;
}



