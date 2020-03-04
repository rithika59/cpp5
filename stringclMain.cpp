#include<iostream>
using namespace std;
#include "stringcl.h"

int main()
{
	const Stringc s1("start");
	const Stringc s2("cdac");
	const Stringc s3("set");
//	Copy constructor
	cout<<"Testing copy constructor \n";
	Stringc s4(s2);
	s4.Print();
	cout<<"copy constructor working!"<<endl;
// = operator
	cout<<"Testing = operator \n";
	Stringc s5("init");
	s5.Print();
	s5=s2;
	s5.Print();
	cout<<"= operator overloading is working! \n";
// [] operator
	cout<<"Testing [] operator \n";
	cout<<"Second char of s5(cdac) is :"<<s5[1]<<endl;
	cout<<"[] operator is working \n";
	return 0;
}
