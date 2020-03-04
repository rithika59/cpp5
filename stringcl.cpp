/* Implement following string functions. do not use any library function from string.h. Use subscript operator to implement them.

char *Strcpy(char *dest , const char *src);
int strCmp(const char *s1, const char *s2);
char *StrCat(char *dest , const char *src);*/

#include<iostream>

using namespace std;
#include "stringcl.h"

Stringc::Stringc()
{
	len=0;
	pt = new char;
	pt[0] = '\0';
}
Stringc::Stringc(char* s)
{
	len = strLen(s);
	pt = new char[len+1];
	StrCpy(pt,s);
}
Stringc::~Stringc()
{
	delete[] pt;
}
Stringc::Stringc(const Stringc& s)
{
	len = s.len;
	pt = new char[len+1];
	StrCpy(pt,s.pt);
}
Stringc& Stringc::operator=(const Stringc& s)
{
	if(len != s.len)
	{
		delete[] pt;
		pt = new char[s.len+1];
	}
	StrCpy(pt,s.pt);
	return *this;
}
void Stringc::Print()
{
	int i=0;
	while(pt[i] != 0)
	{
		cout<<pt[i];
		i++;
	}
	cout<<"\n";
}
char Stringc::operator[](int n)
{
	if(n>=0 && n<len)
		return *(pt+n);
	else
		cout<<"The input exceeded the length of the string. \n";
		return '\0';
}
Stringc Stringc::operator+(Stringc& s)
{
	Stringc temp;
	temp.len = len+s.len;
	temp.pt = new char[temp.len+1];
	StrCpy(temp.pt,pt);
	StrCat(temp.pt,s.pt);
	return temp;
}

bool Stringc::operator==(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i==0)
		return true;
	return false;
}
bool Stringc::operator>(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i==1)
		return true;
	return false;
}

bool Stringc::operator<(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i==-1)
		return true;
	return false;
}
bool Stringc::operator<=(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i==0 || i==-1)
		return true;
	return false;
}

bool Stringc::operator>=(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i==0 || i==1)
		return true;
	return false;
}

bool Stringc::operator!=(const Stringc& s)
{
	int i=StrCmp(pt,s.pt);
	if(i!=0)
		return true;
	return false;
}

int Stringc::strLen(const char *str)
{
	int i=0;
	while(str[i] != 0)
	{
		i++;
	}
	return i;
}	

char* Stringc::StrCpy(char *dest , const char *src)
{
	int i = 0,count =0;
	count = strLen(src);
	while(i != count)
	{
		dest[i] = src[i];
		dest[i+1] = 0;
		i++;
	}
	return dest;
}

int Stringc::StrCmp(const char *s1 , const char *s2)
{

	int r = 23;
	int _lens1 = strLen(s1);
	int _lens2 = strLen(s2);
	if(_lens1 == _lens2)
	{
	for(int i=0;i<_lens1;i++)
	{
		r = s1[i]-s2[i];
		if(r != 0)
			{
//			cout<<i<<s1[i]<<s2[i];
//			cout<<"getting here";
			break;
			}
	}
		cout<<"r value is "<<r<<endl;
		(r<0)?r = -1:r =1;
		return r;
	}else if(_lens1>_lens2)
	{
		return 1;
	}
	else if(_lens2>_lens1)
	{
		return -1;
	}
}

char* Stringc::StrCat(char *dest , const char *src)
{

	int len = strLen(dest);
	int len2 = strLen(src);
	for(int i=len;i<(len+len2);i++)
	{
		dest[i]=src[i-(len)];	
		dest[i+1]=0;
	//	cout<<i<<endl;
	//	cout<<dest[i]<<endl;
	}
	return dest;

}

/*int main()
{
	const char* s1 = "stsing";
	const char* s2 = "string";
	const char* src = "sorting";
	char* dest = NULL;
	char* dest2 = NULL;
	dest = new char[50];	
	dest2 = new char[50];
	int res=0;
	int res2 = strLen(src);

	cout<<"The length of the string "<<src<<" is "<<res2<<endl;
	dest = StrCpy(dest,src);
	cout<<"Copy function result: \n";
	cout<<dest<<endl;
	res = StrCmp(s1,s2);
	cout<<"Compare function result: \n";
	cout<<res<<endl;
	delete[] dest;
	cout<<"Enter a string to concat\n";
	cin>>dest2;
	dest2 = StrCat(dest2,src);
	cout<<"Concat function result: \n";
	cout<<dest2<<endl;
	delete[] dest2;
	return 0;
}*/
