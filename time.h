/* Write Date and time classes that allows you to add , substract , read and print simpke dates in dd/mm/yyyy and time in hh:mm:ss forms.
Use function overloading in your program.Operators to overload =, ==,+,++,--, and [] operators.*/

class Timec
{
    int hh;
    int mm;
    int ss;

public:

    Timec();
    Timec(int h , int m, int s);
    //Timec& Timec(const Timec & t);
    void write();
    Timec operator+(const Timec t);
    Timec& operator=(const Timec t);
    int operator[](const char c);
	bool operator==(const Timec t);
	Timec operator++();
	Timec operator--();
	Timec operator++(int);
	Timec operator--(int);

};
