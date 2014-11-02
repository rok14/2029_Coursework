#include <iostream>
#include <stdlib.h> 

using namespace std;

int gcd( int n, int m)
{
	for(int i=min(n,m);i>0;i--)
	{
		if(div(n, i).rem==0 && div(m, i).rem==0)
		{
			return i;
		}
	}
	return 1;
} //(1 mark) remove the semicolon (;) if you add code;
int lcm( int n, int m); //(1 mark) only classes end with a semicolon (;).
class fraction {
	public:
		fraction() : numer(0), denomer(1) {} //(1 mark) 0/1
		fraction(int n) : numer(n), denomer(1){} //(1 mark) n/1
		fraction(int n, int m)
		{
			if(m!=0)
			{
					int gcdiv=gcd(n ,m);
					numer = n/gcdiv;
					denomer =m/gcdiv;
			}else
			{
				numer=0;
				denomer=0;
			}
		} //(2 marks) n/m SIMPLIFIED; 0/0 when m=0
		int numerator() const { return numer; }// (1 mark)
		int denominator() const { return denomer; }// (1 mark)
		// methods below - 2 marks each
		bool operator==(const fraction &o)
		{
			return o.denominator() == denomer && o.numerator()==numer;
		}
		//(2 marks) use utility & rel_ops to
		//bool operator<(const fraction &o); //(2 marks) get the other operators
		//fraction &operator+=(const fraction &o);//(2 marks)
		//fraction &operator-=(const fraction &o);//(2 marks)
		//fraction &operator*=(const fraction &o);//(2 marks)
		//fraction &operator/=(const fraction &o);//(2 marks)
	private:
		int numer, denomer;
	// ...
};
// you need the following for all operators - they’re too simple; see
// the first one. 1 mark for all 12 of them. (1 mark)
//fraction operator+(fraction a, fraction b) {return a+=b;}
//fraction operator+(int a, fraction b);
//fraction operator+(fraction a, int b); // same for -,*,/
// 2 marks each for the following two
ostream & operator<<( ostream &os, const fraction &f)
{
	os << f.numerator();
	if(f.denominator()!=1)
	{	
		os	<< '/' << f.denominator();
	}
	return os;
} //(2 marks) format: n/m
istream & operator>>( istream &os, fraction &f)
{
	int n, m;
	char fs;//forward slash
	if(!(os >> n >> fs >> m))
	{
		os.setstate(ios::badbit); 
	}else
	{
		if(fs=='/')	
		{
			f= fraction(n, m);
		}
	}
	return os;
}

/*
int main()
{
	fraction f;
	while(cin >>f && f.denominator()!=0)
	{
		cout << f << '\n';
	}
	return 0;
}*/