#include<iostream>
using namespace std;

#include"time.h"

Timec::Timec():hh(0),mm(0),ss(0)
{
}

Timec::Timec(int h, int m,int s)
{
	if(h>0 && m>0 &&s>0)
	{
		if(m<60 && s<60)
		{
			hh=h;
			mm=m;
			ss=s;
		}
		else
		{
			cout<<"Minutes and seconds must not be more than 60. \n";
			exit(0);
		}
	}
	else
	{
		cout<<"Cannot accept negative values.\n";
		exit(0);
	}
}

Timec& Timec::operator=(const Timec t)
{
    hh = t.hh;
    mm = t.mm;
    ss = t.ss;
//	cout<<hh<<":"<<mm<<":"<<ss<<endl;
 //   cout<<"coming here";
	return *this;
}

int Timec::operator[](char c)
{
    switch(c)
    {
    case 'h':
        return hh;
        break;
    case 'm':
        return mm;
        break;
    case 's':
        return ss;
        break;
    default:
        cout<<"Enter valid input.";
        return 0;
        break;
    }

}
bool Timec::operator==(Timec t)
{
	if((hh==t.hh)&&(mm==t.mm)&&(ss==t.ss))
	 return true;
	return false;
		
}
Timec Timec::operator++()
{
	hh++;
	return *this;

}
Timec Timec::operator--()
{
	if(hh>1){
	hh--;
	}
	else
	{
		cout<<"Hour value is 0 cannot decrement more. \n";
	}
	return *this;
}
Timec Timec::operator++(int)
{
	Timec t1 = *this;
	++hh;
	return t1;
}
Timec Timec::operator--(int)
{
	Timec t1 = *this;
	if(hh>1){
	--hh;
	}
	else
	{
		cout<<"Hour value is 0 cannot decrement more. \n";
	}
	return t1;
}

void Timec::write()
{
    cout<<hh<<":"<<mm<<":"<<ss<<endl;
}
Timec Timec::operator+(const Timec t)
{
    Timec sum;
    int var1 = ss+t.ss;
//	cout<<var1<<endl;
    int var2 = mm+t.mm+((var1)/60);
//	cout<<var2<<endl;
    sum.ss = var1%60;
    sum.mm = var2%60;
    sum.hh = hh+t.hh+(var2/60);
//	cout<<sum.hh<<":"<<sum.mm<<":"<<sum.ss;
    return sum;
}
