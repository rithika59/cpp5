#include<iostream>
using namespace std;

class Stringc
{
	int len;
	char* pt;
public:
	Stringc();
	Stringc(char*);
	~Stringc();
	Stringc operator+(Stringc& s);
	char operator[](int n);
	Stringc(const Stringc& s);
	Stringc& operator=(const Stringc& s);
	bool operator==(const Stringc& s);
	bool operator<(const Stringc& s);
	bool operator>(const Stringc& s);
	bool operator>=(const Stringc& s);
	bool operator<=(const Stringc& s);
	bool operator!=(const Stringc& s);
	void Print();
	int strLen(const char *str);
	char *StrCpy(char *dest,const char *src);
	int StrCmp(const char* s1, const char* s2);
	char *StrCat(char *dest, const char *src);

};
