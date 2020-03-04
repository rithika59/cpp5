#include<iostream>
using namespace std;

int getMax(int m,int y)
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
	cout<<"max of month "<<m<<"is"<<max<<endl;
	return max;
};


int* t_add(int* q)
{

			int max1 = getMax(q[2],q[3]);
			if((q[1]+q[0])<=max1)
			{
				q[1] = q[1]+q[0];
				cout<<"coming here";
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

int main()
{
int t = 3;
int d = 31;
int m1 = 12;
int y1 = 1990;


int *p = NULL;
p = new int(4);
p[0] = t;
p[1] = d;
p[2] = m1;
p[3] = y1;

int *q1 = NULL;
q1 = new int(4);
q1 = t_add(p);
cout<<"result is "<<q1[1]<<"/"<<q1[2]<<"/"<<q1[3];
    // add t days
	//int *p1 = (int*)malloc(4*sizeof(int));
//	int *p1 = NULL; 
/*
//while(t>=0)
//{
			int max1 = getMax(m1,y1);
			
			if((d+t)<=max1)
			{
				d = d+t;
				cout<<"coming here \n";
				cout<<"result is"<<d<<"/"<<m1<<"/"<<y1<<endl;
				

			}
			else{
				t = t-(max1-d);
				if(m1 == 12)
				{
					y1 += 1;
				}
				m1 = (m1+1)/12;
				//cout<<"result is"<<d<<"/"<<m1<<"/"<<y1<<endl;
				t_add();
			}	
					
//}*/

return 0;
}
