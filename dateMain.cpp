#include<iostream>
using namespace std;

#include "date.h"

int main()
{
	/*Datec d1(3,3,2019);
	d1.write();
	d1+(-6);
	d1.write();
	
	cout<<"copy copnstructor"<<endl;
	Datec d2(1,3,2020);
	d1=d2;
	d1.write();

	cout<<"suvscript opearator"<<endl;
	int i = d1['m'];
	cout<<"d1 obj is"<<endl;
	d1.write();
	cout<<"\n";

	cout<<"month is obj"<<i<<endl;
	
	cout<<"increment"<<endl;
	d2.write();
	++d2;
	d2.write();*/
	int d,m,y,t;
	cout<<"Enter a date (dd mm yy)\n";
	cin>>d>>m>>y;
	Datec d1(d,m,y);
	cout<<"Enter the number of days to add to this date: \n";
	cin>>t;
	d1+t;
	cout<<"Result date : \n";
	d1.write();
	cout<<endl;

	return 0;
}
