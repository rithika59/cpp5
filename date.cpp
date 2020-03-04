#include<iostream>
using namespace std;

#include"date.h"

Datec::Datec():dd(1),mm(1),yy(1800)
{
}

Datec::Datec(int d, int m,int y)
{	
	bool pass = isValid(d,m,y);
	if(pass)
	{
		dd = d;
		mm = m;
		yy = y;
	}
	else{
		cout<<"Date is invalid";
		exit(0);
	}
}

Datec& Datec::operator=(const Datec d)
{
    dd = d.dd;
    mm = d.mm;
    yy = d.yy;
	return *this;
}

int Datec::operator[](char c)
{
    switch(c)
    {
    case 'd':
        return dd;
        break;
    case 'm':
        return mm;
        break;
    case 'y':
        return yy;
        break;
    default:
        cout<<"Enter valid input.";
        return 0;
        break;
    }

}
bool Datec::operator==(Datec d)
{
	if((dd==d.dd)&&(mm==d.mm)&&(yy==d.yy))
	 return true;
	return false;
		
}

Datec& Datec::operator++()
{
	this->Datec::operator+(1);
	return *this;
}
Datec& Datec::operator--()
{
	this->Datec::operator+(-1);
	return *this;
	
}
Datec& Datec::operator++(int)
{	
	Datec t = *this;
	this->Datec::operator+(1);
	return t;
}
Datec& Datec::operator--(int)
{
	Datec t = *this;
	this->Datec::operator+(-1);
	return t;
	
}

void Datec::write()
{
    cout<<dd<<":"<<mm<<":"<<yy<<endl;
}

int* Datec::t_add(int* q)
{
	int max1 = getMax(q[2],q[3]);
	if(q[0]>0)
	{		
			if((q[1]+q[0])<=max1)
			{
				q[1] = q[1]+q[0];
				return q;

			}
			else{
				q[0] = (q[0])-(max1-q[1]);
				q[1] = 1;
				if(q[2] == 12)
				{
					q[3] += 1;
					q[2] = 1;
				}
				else{
					q[2] = q[2]+1;
				}
			int	max2 = getMax(q[2],q[3]);
				if(q[0]<max2)
				{
					q[1] = q[0];
					return q;
				}
				else{
					t_add(q);
				}
			}
	}
	else{
			if((q[1]+q[0])<=max1 && q[1]+q[0]>0)
			{
				q[1] = q[1]+q[0];
				return q;

			}
			else{
				q[0] = q[0]+q[1];
				if(q[2] == 1)
				{
					q[3] -= 1;
					q[2] = 12;
				}
				else{
					q[2] = q[2]-1;
				}
			int	max2 = getMax(q[2],q[3]);
				q[1] = max2;
				if((-q[0])<max2)
				{
					q[1] = max2+q[0];
					return q;
				}
				else{
					t_add(q);
				}
			}

	}
}

Datec& Datec::operator+(int t)
{
	int day = dd;
	int mth = mm;
	int yr = yy;
	int *p = NULL;
	p = new int(4);
	p[0] = t;
	p[1] = dd;
	p[2] = mm;
	p[3] = yy;
	//int *p1 = (int*)malloc(4*sizeof(int));
	//int *p1 = new int(4);
	p = t_add(p);
	dd = p[1];
	mm = p[2];
	yy = p[3];
	//delete[] p1;
	delete[] p;
	return *this;

}
bool Datec::isValid(int d,int m, int y)
{
	int max = 0;
	bool valid = false;
	//check year range
	if(1800<y && y<2300)
	{
	//	yy=y;
	
		//check month range
		if(m>0 && m<13)
		{
			max = getMax(m,y);
		
			//check date range
			if(d>0 && d<=max)
			{
			//	dd=d;
				valid = true;
			}
//			else
//			{
			//	cout<<"Date is invalid \n";
			//	exit(0);
//			}
		
		}
//		else{
		//	cout<<"Enter a valid month 1-12. \n";
		//	exit(0);
//		}
	}
//	else
//	{
	//	cout<<"Enter a valid year between 1800-2300. \n";
	//	exit(0);
//	}
	return valid;
}

int Datec::getMax(int m,int y)
{
	int max =0;
	bool leap = false;
		//check leap year
		if((y%4 == 0) || ((y%100 != 0)) &&(y%400 == 0))
		{
			leap = true;
		}
			//assign max days for month
			if(m == 2)
			{
				leap?max=29:max=28;
			}else if(m==4 || m==6 || m==9 || m==11)
			{
				max = 30;
			}
			else
				max = 31;
	cout<<"max of "<<m<<" is "<<max<<endl;
	return max;
}
