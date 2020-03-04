// Write Date and time classes that allows you to add , substract , read and print simpke dates in dd/mm/yyyy and time in hh:mm:ss forms.
//Use function overloading in your program.Operators to overload =, ==,+,++,--, and [] operators.*/

class Datec
{	int dd;
    int mm;
    int yy;
 public:
    Datec();
    Datec(int d , int m, int y);
    void write();
    Datec& operator+(int t);
    Datec& operator=(const Datec t);
    int operator[](const char c);
	bool operator==(const Datec t);
	Datec& operator++();
	Datec& operator--();
	Datec& operator++(int);
	Datec& operator--(int);
	int getMax(int m, int y);
	bool isValid(int d,int m, int y);
	int* t_add(int* q);
};
