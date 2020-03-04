#include<iostream>
using namespace std;

#include"time.h"


int main()
{
    Timec t1(1,1,12);
    Timec t2(-2,3,15);
	Timec t3;
//	t1.write();
//    t2.write();
	t3=(t2+t1);
	t3.write();
	int i = t2['s'];
	cout<<"t2 obj is"<<endl;
	t2.write();
	cout<<"\n";
	cout<<"The seconds in t2 obj: "<<i<<endl;
	
	cout<<"t2 obj is"<<endl;
	t2.write();
	cout<<"\n";
	cout<<"Incrementing t2 twice"<<endl;
	t2++;
	++t2;
	t2.write();
	cout<<"\n";
	cout<<"t1 obj is"<<endl;
	t1.write();
	cout<<"\n";
	cout<<"Decrementing t1 twice"<<endl;
	t1--;
	--t1;
	t1.write();
	cout<<"\n";


	return 0;
}
